#include "stc8h.h"

#define CONF_IRCBAND 0x00                 ///< 20MHz Band IRC, 0x00 = 20MHz , 0x01 = 35MHz +/- trim
#define FIRC         24000000UL           ///< Target value for internal RC OSCILLATOR
#define CONF_CLKDIV  0x02                 ///< 1:2
#define FOSC         (FIRC / CONF_CLKDIV) ///< System clock frequency

void led_off() {
  P3 = 0b11111111;
  P5 = 0b11111111;
}
void led_on() {
  P3 = 0b11110001;
  P5 = 0b11001111;
}

void shutdown() {
  led_off();
  ADC_CONTR = 0; // adc power off
  WKTCH = 0;
  PCON |= 0x02;  // Enter power-down mode
}

uint8_t adc_sample() {
  uint8_t i = 10;
  ADC_CONTR |= 0b01000000;
  while (i) i--;
  while (!(ADC_CONTR & 0b00100000));
  ADC_CONTR &= ~0b00100000;
  return ADC_RES;
}

void hardware_init(void) {
  P1M0 = 0b00000000;
  P1M1 = 0b00000000;

  P3M0 = 0b00000100;
  P3M1 = 0b00000000;

  P5M0 = 0b00000000;
  P5M1 = 0b00000000;

  // Defined output + Quasibidirectional = lowest power consumption for floating pins
  P1 = 0b11111111;
  P3 = 0b11111111;
  P5 = 0b11111111;

  // PIN Function
  PSW1 = 0b00000000;
  PSW2 = 0b00000000;

  // Auxiliary register configuration
  AUXR = 0b01000000; // T1 = SysClk/2, T0 = SysClk/12

  // Clock configuration
  SFRX_ON();
  ADCTIM = 0b00011111;
  int i = 5;
  if (IRCBAND != (CONF_IRCBAND)) {
    IRCBAND = (CONF_IRCBAND);
    while (--i); // Wait a while after clock changed, or it may block the main process
  }
  i = 5;
  if (CLKDIV != (CONF_CLKDIV)) {
    CLKDIV = (CONF_CLKDIV);
    while (--i); // Wait a while after clock changed, or it may block the main process
  }
  SFRX_OFF();

  // slow sampling of reference 1.19V
  ADCCFG = 0b00001111;
  ADC_CONTR = 0b10001111;
}

#define TICKS_PER_SECOND 1675
#define MAX_SECS_PER_SLEEP 15

void sleep(uint8_t seconds) {
  while (seconds) {
    /* MAX 19 seconds per iteration to not exceed 15 bits
     * (if the clock was 32 kHz as datasheet says, that would be max 16) */
    uint8_t part = seconds;
    if (part > MAX_SECS_PER_SLEEP) { part = MAX_SECS_PER_SLEEP; }
    seconds -= part;

    /* ticks per second coefficient is chosen empirically.
     * Actual freq seems to be about 26.8 kHz
     * Datasheet lies about measured freq saved in flash at 0x1ff5
     * Both STC-ISP tool and stcgal lie about actual freq = 36.25 kHz */
    uint16_t tvalue = TICKS_PER_SECOND * part;
    WKTCL = tvalue & 0xff;
    WKTCH = ((tvalue >> 8) & 0x7f) | 0x80;
    PCON |= 0x02;  // Enter power-down mode
  }
}

void decisleep(uint8_t deciseconds) {
  uint16_t tvalue = 164 * deciseconds;
  WKTCL = tvalue & 0xff;
  WKTCH = ((tvalue >> 8) & 0x7f) | 0x80;
  PCON |= 0x02;  // Enter power-down mode
}

void blink(uint8_t count) {
  while (count--) {
    led_off();
    decisleep(3);
    led_on();
    decisleep(3);
  }
}

void sleep_1min() {
  sleep(59);
  /* Last second of every minute may used for battery warning.
   * If battery is OK, just sleep the remaining second.
   * If battery is low, blink few times accordind to how low it is.
   * On critical voltage, shut down to prevent battery damage */
  uint8_t adc = adc_sample();
  if (adc <= 83) { // VCC >= 3.67
    sleep(1);
  } else if (adc <= 86) { // VCC >= 3.54
    blink(1);
  } else if (adc <= 92) { // VCC >= 3.3
    blink(2);
  } else if (adc <= 95) { // VCC >= 3.2
    blink(3);
  } else {
    shutdown();
  }
}

void sleep_1hr() {
  for (int j=0; j<60; j++) { sleep_1min(); }
}

void sleep_hm(uint8_t hr, uint8_t min) {
  uint8_t i;
  for (i=0; i<hr; i++) { sleep_1hr(); }
  for (i=0; i<min; i++) { sleep_1min(); }
}

void main() {
  hardware_init();

  led_on();

  // several cycles to make sure ADC has fully initialized
  decisleep(1); adc_sample();
  decisleep(1); adc_sample();
  decisleep(1);
  uint8_t adc = adc_sample();
  // On low battery blink and shutdown instantly
  if (adc > 95) { // VCC < 3.2
    blink(4); // actually 5 pulses here because adc init above is +1 pulse
    shutdown();
  }

  // Main mode: work for some time, then shutdown to save energy
  sleep_hm(4, 20);

  shutdown();
}
