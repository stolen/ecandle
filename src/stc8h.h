/**
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file stc8h1.h SFR Definitions for the STC8H1 chipset.
 * @author Thomas Reidemeister
 */
#ifndef STC8H1_H
#define STC8H1_H

#include <stdint.h>
#include <mcs51/compiler.h>
#include <mcs51/8051.h>

/******************************************************************************\
 * Public type definitions
\******************************************************************************/

/******************************************************************************\
 * Public macros
\******************************************************************************/

#define ADC_VECTOR      5    ///< 0x2B ADC
#define LVD_VECTOR      6    ///< 0x33 LVD
#define PCA_VECTOR      7    ///< 0x3B PCA
#define SI1_VECTOR      8    ///< 0x43 UART2
#define SPI_VECTOR      9    ///< 0x4B SPI
#define IE2_VECTOR      10   ///< 0x53 INT2 
#define IE3_VECTOR      11   ///< 0x5B INT3
#define TF2_VECTOR      12   ///< 0x63 Timer2
#define IE4_VECTOR      16   ///< 0x83 INT4
#define SI3_VECTOR      17   ///< 0x8B UART3
#define SI4_VECTOR      18   ///< 0x93 UART4
#define TF3_VECTOR      19   ///< 0x9B Timer3
#define TF4_VECTOR      20   ///< 0xA3 Timer4
#define CMP_VECTOR      21   ///< 0xAB Comparator
#define I2C_VECTOR      24   ///< 0xC3 I2C
#define USB_VECTOR      25   ///< 0xCB USB
#define PWMA_VECTOR     26   ///< 0xD3 PWMA
#define PWMB_VECTOR     27   ///< 0xDB PWMB
#define TKSU_VECTOR     35   ///< 0x11B Touch Key Start Up
#define RTC_VECTOR      36   ///< 0x123 RTC

// XData SFR Switch
#define SFRX_ON()             (PSW2 |= 0x80)
#define SFRX_OFF()            (PSW2 &= ~0x80)

/******************************************************************************\
 * Public memory declarations
\******************************************************************************/

// SFRs for peripheral fucntions
SFR(PSW1, 0xA2);            ///< Peripheral port switch register 1.
SFR(PSW2, 0xBA);            ///< Peripheral port switch register 2.

SFRX(MCLKOCR, 0xFE05);      ///< Main clock output control register
SFRX(PWMA_PS, 0xFEB2);      ///< PWM1 switch register
SFRX(PWMB_PS, 0xFEB6);      ///< PWM2 switch register
SFRX(PWMA_ETRPS, 0xFEB0);   ///< PWMA ETR select register
SFRX(PWMB_ETRPS, 0xFEB4);   ///< PWMB ETR select register
SFRX(T3T4PIN, 0xFEAC);      ///< T3/T4 select register

// SFRs for the clock configuration
SFRX(CKSEL, 0xFE00);      ///< Clock selection register
SFRX(CLKGIV, 0xFE01);     ///< Clock Division Register
SFRX(IRCCR, 0xFE02);      ///< Internal Oscillator control register
SFRX(XOSCCR, 0xFE03);     ///< External Oscillator control register
SFRX(IRC32KCR, 0xFE04);   ///< Internal 32KHz Oscillator control register
SFRX(MCLKOCR, 0xFE05);    ///< Main clock output control register
SFRX(X32KCR, 0xFE08);     ///< External 32KHz Oscillator control register

// ROM ID Settings
#define READ_CODE8(__ADDR__) (*(uint8_t volatile __code *)(__ADDR__))
#define READ_CODE16(__ADDR__) (*(uint16_t volatile __code *)(__ADDR__))

// Flash size
#define SERIES_K08 0x2000u
#define SERIES_K12 0x3000u
#define SERIES_K16 0x4000u
#define SERIES_K17 0x4400u
#define SERIES_K24 0x6000u
#define SERIES_K28 0x7000u
#define SERIES_K33 0x8000u

// Note these have to be enabled in the utility "Add reset code in front of ID" in util, no option in stcgal
#define IRC24M(SERIES) READ_CODE8(SERIES - 0x0Du)     ///< IRC parameter of 24MHz (20M band)
#define IRC22M(SERIES) READ_CODE8(SERIES - 0x0Cu)     ///< IRC parameter of 22.1184MHz (20M band)
#define WKUP_FREQ(SERIES) READ_CODE16(SERIES - 0x0Bu) ///< 32K Power-down wake-up timer frequency (high byte)
#define VREF(SERIES) READ_CODE16(SERIES - 0x09u)      ///< Internal 1.19V reference signal source (high byte)

// Only this is available by default
#define CHIPID00(SERIES) READ_CODE8(SERIES - 0x07u)   ///< Globally Unique ID Number (0th byte)
#define CHIPID01(SERIES) READ_CODE8(SERIES - 0x06u)   ///< Globally Unique ID Number (1st byte)
#define CHIPID02(SERIES) READ_CODE8(SERIES - 0x05u)   ///< Globally Unique ID Number (2nd byte)
#define CHIPID03(SERIES) READ_CODE8(SERIES - 0x04u)   ///< Globally Unique ID Number (3rd byte)
#define CHIPID04(SERIES) READ_CODE8(SERIES - 0x03u)   ///< Globally Unique ID Number (4th byte)
#define CHIPID05(SERIES) READ_CODE8(SERIES - 0x02u)   ///< Globally Unique ID Number (5th byte)
#define CHIPID06(SERIES) READ_CODE8(SERIES - 0x01u)   ///< Globally Unique ID Number (6th byte)

SFR(AUXR, 0x8E);          ///< Auxiliary register
SFR(S4CON, 0x84);         ///< UART 4 control register
SFR(S4BUF, 0x85);         ///< UART 4 data buffer register
SFR(AUXR, 0x8E);          ///< Auxiliary register 1
SFR(INTCLKO, 0x8F);       ///< External interrupt and clock output control register
SFR(P1M1, 0x91);          ///< Port 1 mode register 1
SFR(P1M0, 0x92);          ///< Port 1 mode register 0
SFR(P0M1, 0x93);          ///< Port 0 mode register 1
SFR(P0M0, 0x94);          ///< Port 0 mode register 0
SFR(P2M1, 0x95);          ///< Port 2 mode register 1
SFR(P2M0, 0x96);          ///< Port 2 mode register 0
SFR(S2CON, 0x9A);         ///< UART 2 control register
SFR(S2BUF, 0x9B);         ///< UART 2 data buffer register
SFR(IRCBAND, 0x9D);       ///< IRC band selection register
SFR(LIRTRIM, 0x9E);       ///< IRC band selection detection
SFR(INTRIM, 0x9F);        ///< IRC frequency adjustment register
SFR(BUS_SPEED, 0xA1);     ///< Bus speed control register
  SBIT(EADC, 0xA8, 5);    ///< Interrupt enable ADC
  SBIT(ELVD, 0xA8, 6);    ///< Interrupt enable Low Voltage Detect
SFR(SADDR, 0xA9);         ///< UART1 slave address register
SFR(WKTCL, 0xAA);         ///< Wake-up Timer Control Register Low Byte
SFR(WKTCH, 0xAB);         ///< Wake-up Timer Control Register High Byte
SFR(S3CON, 0xAC);         ///< UART 3 control register
SFR(S3BUF, 0xAD);         ///< UART 3 data buffer register
SFR(TA, 0xAE);            ///< DPTR Timing control register
SFR(IE2, 0xAF);           ///< Interrupt enable register 2
SFR(P3M1, 0xB1);          ///< Port 3 mode register 1
SFR(P3M0, 0xB2);          ///< Port 3 mode register 0
SFR(P4M1, 0xB3);          ///< Port 4 mode register 1
SFR(P4M0, 0xB4);          ///< Port 4 mode register 0
SFR(IP2, 0xB5);           ///< 2nd Interrupt Priority register low byte
SFR(IP2H, 0xB6);          ///< 2nd Interrupt Priority register high byte
SFR(IPH, 0xB7);           ///< Interrupt Priority High Byte
SFR(SADEN, 0xB9);         ///< UART1 slave address enable register
SFR(ADC_CONTR, 0xBC);     ///< ADC control register
SFR(ADC_RES, 0xBD);       ///< ADC result high byte
SFR(ADC_RESL, 0xBE);      ///< ADC result low byte
SFR(P4, 0xC0);            ///< Port 4
  SBIT(P4_0, 0xC0, 0);    ///< Port 4 pin 0
  SBIT(P4_1, 0xC0, 1);    ///< Port 4 pin 1
  SBIT(P4_2, 0xC0, 2);    ///< Port 4 pin 2
  SBIT(P4_3, 0xC0, 3);    ///< Port 4 pin 3
  SBIT(P4_4, 0xC0, 4);    ///< Port 4 pin 4
  SBIT(P4_5, 0xC0, 5);    ///< Port 4 pin 5
  SBIT(P4_6, 0xC0, 6);    ///< Port 4 pin 6
  SBIT(P4_7, 0xC0, 7);    ///< Port 4 pin 7
SFR(IAP_DATA, 0xC2);      ///< IAP Flash Data Register
SFR(IAP_ADDRH, 0xC3);     ///< IAP Flash Address High Byte
SFR(IAP_ADDRL, 0xC4);     ///< IAP Flash Address Low Byte
SFR(IAP_CMD, 0xC5);       ///< IAP Flash Command Register
SFR(IAP_TRIG, 0xC6);      ///< IAP Flash Trigger Register
SFR(IAP_CONTR, 0xC7);     ///< IAP Control Register
SFR(P5, 0xC8);            ///< Port 5
  SBIT(P5_0, 0xC8, 0);    ///< Port 5 pin 0
  SBIT(P5_1, 0xC8, 1);    ///< Port 5 pin 1
  SBIT(P5_2, 0xC8, 2);    ///< Port 5 pin 2
  SBIT(P5_3, 0xC8, 3);    ///< Port 5 pin 3
  SBIT(P5_4, 0xC8, 4);    ///< Port 5 pin 4
  SBIT(P5_5, 0xC8, 5);    ///< Port 5 pin 5
  SBIT(P5_6, 0xC8, 6);    ///< Port 5 pin 6
  SBIT(P5_7, 0xC8, 7);    ///< Port 5 pin 7
SFR(P5M1, 0xC9);          ///< Port 5 mode register 1
SFR(P5M0, 0xCA);          ///< Port 5 mode register 0
SFR(P6M1, 0xCB);          ///< Port 6 mode register 1
SFR(P6M0, 0xCC);          ///< Port 6 mode register 0
SFR(SPSTAT, 0xCD);        ///< SPI status register
SFR(SPCTL, 0xCE);         ///< SPI Control Register
SFR(SPDAT, 0xCF);         ///< SPI Data Register
SFR(T4T3M, 0xD1);         ///< Timer 4 and Timer 3 Control Register
SFR(T4H, 0xD2);           ///< Timer 4 high byte register
SFR(T4L, 0xD3);           ///< Timer 4 low byte register
SFR(T3H, 0xD4);           ///< Timer 3 high byte register
SFR(T3L, 0xD5);           ///< Timer 3 low byte register
SFR(T2H, 0xD6);           ///< Timer 2 high byte register
SFR(T2L, 0xD7);           ///< Timer 2 low byte register
SFR(USBCLK, 0xDC);        ///< USB clock control register
SFR(ADCCFG, 0xDE);        ///< ADC Configuration Register
SFR(IP3, 0xDF);           ///< 3rd Interrupt Priority register low byte
SFR(P7M1, 0xE1);          ///< Port 7 mode register 1
SFR(P7M0, 0xE2);          ///< Port 7 mode register 0
SFR(DPS, 0xE3);           ///< DPTR Selection Register
SFR(DPL1, 0xE4);          ///< 2nd Data pointer low byte
SFR(DPH1, 0xE5);          ///< 2nd Data pointer high byte
SFR(CMPCR1, 0xE6);        ///< Comparator Control Register 1
SFR(CMPCR2, 0xE7);        ///< Comparator Control Register 2
SFR(P6, 0xE8);            ///< Port 6
  SBIT(P6_0, 0xE8, 0);    ///< Port 6 pin 0
  SBIT(P6_1, 0xE8, 1);    ///< Port 6 pin 1
  SBIT(P6_2, 0xE8, 2);    ///< Port 6 pin 2
  SBIT(P6_3, 0xE8, 3);    ///< Port 6 pin 3
  SBIT(P6_4, 0xE8, 4);    ///< Port 6 pin 4
  SBIT(P6_5, 0xE8, 5);    ///< Port 6 pin 5
  SBIT(P6_6, 0xE8, 6);    ///< Port 6 pin 6
  SBIT(P6_7, 0xE8, 7);    ///< Port 6 pin 7
SFR(USBDAT, 0xEC);        ///< USB Data register high byte
SFR(IP3H, 0xF7);          ///< 3rd Interrupt Priority register high byte
SFR(AUXINTF, 0xEF);       ///< Extended External Interrupt Flag Register
SFR(P7, 0xF8);            ///< Port 7
  SBIT(P7_0, 0xF8, 0);    ///< Port 7 pin 0
  SBIT(P7_1, 0xF8, 1);    ///< Port 7 pin 1
  SBIT(P7_2, 0xF8, 2);    ///< Port 7 pin 2
  SBIT(P7_3, 0xF8, 3);    ///< Port 7 pin 3
  SBIT(P7_4, 0xF8, 4);    ///< Port 7 pin 4
  SBIT(P7_5, 0xF8, 5);    ///< Port 7 pin 5
  SBIT(P7_6, 0xF8, 6);    ///< Port 7 pin 6
  SBIT(P7_7, 0xF8, 7);    ///< Port 7 pin 7
SFR(IAP_TPS, 0xF9);       ///< IAP Waiting Time Control Register
SFR(RSTCFG, 0xFF);        ///< Reset Configuration Register

// XSFR
SFRX(CKSEL, 0xFE00);      ///< Clock Select Register
SFRX(CLKDIV, 0xFE01);     ///< Clock Divide Register
SFRX(HIRCCR, 0xFE02);     ///< Internal high-speed oscillator Control Register
SFRX(XOSCCR, 0xFE03);     ///< External Oscillator Control Register
SFRX(IRC32KCR, 0xFE04);   ///< Internal 32K Oscillator Control Register
SFRX(MCLKOCR, 0xFE05);    ///< Main Clock Output Control Register
SFRX(IRCDB, 0xFE06);      ///< Internal high-speed oscillator debounce control
SFRX(IRC48MCR, 0xFE07);   ///< Internal 48M Oscillator Control Register
SFRX(SPFUNC, 0xFE08);     ///< Special Function Control Register
SFRX(RSTFLAG, 0xFE09);    ///< Reset flag register
SFRX(P0PU, 0xFE10);       ///< P0 Pull-up Resistor Control Register
SFRX(P1PU, 0xFE11);       ///< P1 Pull-up Resistor Control Register
SFRX(P2PU, 0xFE12);       ///< P2 Pull-up Resistor Control Register
SFRX(P3PU, 0xFE13);       ///< P3 Pull-up Resistor Control Register
SFRX(P4PU, 0xFE14);       ///< P4 Pull-up Resistor Control Register
SFRX(P5PU, 0xFE15);       ///< P5 Pull-up Resistor Control Register
SFRX(P6PU, 0xFE16);       ///< P6 Pull-up Resistor Control Register
SFRX(P7PU, 0xFE17);       ///< P7 Pull-up Resistor Control Register
SFRX(P0NCS, 0xFE18);      ///< P0 Schmitt Trigger Control Register
SFRX(P1NCS, 0xFE19);      ///< P1 Schmitt Trigger Control Register
SFRX(P2NCS, 0xFE1A);      ///< P2 Schmitt Trigger Control Register
SFRX(P3NCS, 0xFE1B);      ///< P3 Schmitt Trigger Control Register
SFRX(P4NCS, 0xFE1C);      ///< P4 Schmitt Trigger Control Register
SFRX(P5NCS, 0xFE1D);      ///< P5 Schmitt Trigger Control Register
SFRX(P6NCS, 0xFE1E);      ///< P6 Schmitt Trigger Control Register
SFRX(P7NCS, 0xFE1F);      ///< P7 Schmitt Trigger Control Register
SFRX(P0SR, 0xFE20);       ///< P0 Level Shift Rate Register
SFRX(P1SR, 0xFE21);       ///< P1 Level Shift Rate Register
SFRX(P2SR, 0xFE22);       ///< P2 Level Shift Rate Register
SFRX(P3SR, 0xFE23);       ///< P3 Level Shift Rate Register
SFRX(P4SR, 0xFE24);       ///< P4 Level Shift Rate Register
SFRX(P5SR, 0xFE25);       ///< P5 Level Shift Rate Register
SFRX(P6SR, 0xFE26);       ///< P6 Level Shift Rate Register
SFRX(P7SR, 0xFE27);       ///< P7 Level Shift Rate Register
SFRX(P0DR, 0xFE28);       ///< P0 Drive Current Control Register
SFRX(P1DR, 0xFE29);       ///< P1 Drive Current Control Register
SFRX(P2DR, 0xFE2A);       ///< P2 Drive Current Control Register
SFRX(P3DR, 0xFE2B);       ///< P3 Drive Current Control Register
SFRX(P4DR, 0xFE2C);       ///< P4 Drive Current Control Register
SFRX(P5DR, 0xFE2D);       ///< P5 Drive Current Control Register
SFRX(P6DR, 0xFE2E);       ///< P6 Drive Current Control Register
SFRX(P7DR, 0xFE2F);       ///< P7 Drive Current Control Register
SFRX(P0IE, 0xFE30);       ///< P0 Input Enable Control Register
SFRX(P1IE, 0xFE31);       ///< P1 Input Enable Control Register
SFRX(P2IE, 0xFE32);       ///< P2 Input Enable Control Register
SFRX(P3IE, 0xFE33);       ///< P3 Input Enable Control Register
SFRX(P4IE, 0xFE34);       ///< P4 Input Enable Control Register
SFRX(P5IE, 0xFE35);       ///< P5 Input Enable Control Register
SFRX(P6IE, 0xFE36);       ///< P6 Input Enable Control Register
SFRX(P7IE, 0xFE37);       ///< P7 Input Enable Control Register
SFRX(LCMIFCFG, 0xFE50);   ///< LCM Interface Configuration Register
SFRX(LCMIFCFG2, 0xFE51);  ///< LCM Interface Configuration Register 2
SFRX(LCMIFCR, 0xFE52);    ///< LCM Interface Control Register
SFRX(LCMIFSTA, 0xFE53);   ///< LCM Interface Status Register
SFRX(LCMDIDATL, 0xFE54);  ///< LCM Interface low byte data
SFRX(LCMDIDATH, 0xFE55);  ///< LCM Interface high byte data
SFRX(RTCCR, 0xFE60);      ///< RTC Control Register
SFRX(RTCCFG, 0xFE61);     ///< RTC Configuration Register
SFRX(RTCIEN, 0xFE62);     ///< RTC Interrupt Enable Register
SFRX(RTCIF, 0xFE63);      ///< RTC Interrupt Request Register
SFRX(ALAHOUR, 0xFE64);    ///< The hour value of the RTC alarm
SFRX(ALAMIN, 0xFE65);     ///< The minute value of the RTC alarm
SFRX(ALASEC, 0xFE66);     ///< The second value of the RTC alarm
SFRX(ALASSEC, 0xFE67);    ///< 1/128 second value of the RTC alarm
SFRX(INIYEAR, 0xFE68);    ///< Initialization of RTC year
SFRX(INIMONTH, 0xFE69);   ///< Initialization of RTC month
SFRX(INIDAY, 0xFE6A);     ///< Initialization of RTC day
SFRX(INIHOUR, 0xFE6B);    ///< Initialization of RTC hour
SFRX(INIMIN, 0xFE6C);     ///< Initialization of RTC minute
SFRX(INISEC, 0xFE6D);     ///< Initialization of RTC second
SFRX(INISSEC, 0xFE6E);    ///< Initialization of RTC 1/128 second
SFRX(YEAR, 0xFE70);       ///< Year count value of RTC
SFRX(MONTH, 0xFE71);      ///< Month count value of RTC
SFRX(DAY, 0xFE72);        ///< Day count value of RTC
SFRX(HOUR, 0xFE73);       ///< Hour count value of RTC
SFRX(MIN, 0xFE74);        ///< Minute count value of RTC
SFRX(SEC, 0xFE75);        ///< Second count value of RTC
SFRX(SSEC, 0xFE76);       ///< 1/128 second count value of RTC
SFRX(I2CCFG, 0xFE80);     ///< I2C Configuration Register
SFRX(I2CMSCR, 0xFE81);    ///< I2C Master Control Register
SFRX(I2CMSST, 0xFE82);    ///< I2C Master Status Register
SFRX(I2CSLCR, 0xFE83);    ///< I2C Slave Control Register
SFRX(I2CSLST, 0xFE84);    ///< I2C Slave Status Register
SFRX(I2CSLADR, 0xFE85);   ///< I2C Slave Address Register
SFRX(I2CTXD, 0xFE86);     ///< I2C Data Transmission Register
SFRX(I2CRXD, 0xFE87);     ///< I2C Data Receive Register
SFRX(I2CMSAUX, 0xFE88);   ///< I2C Master Auxiliary Control Register
SFRX(T2P5, 0xFEA2);       ///< Timer2 Clock Prescaler Register
SFRX(T3P5, 0xFEA3);       ///< Timer3 Clock Prescaler Register
SFRX(T4P5, 0xFEA4);       ///< Timer4 Clock Prescaler Register
SFRX(ADCTIM, 0xFEA8);     ///< ADC Timing Control Register
SFRX(ADCEXCFG, 0xFEA9);   ///< ADC Extended Configuration Register
SFRX(CMPEXCFG, 0xFEAE);   ///< Comparator Extended Configuration Register
SFRX(T3T4PIN, 0xFEAC);    ///< T3/T4 Select register
SFRX(PWMA_ETRPS, 0xFEB0); ///< PWMA ETR Select register
SFRX(PWMA_ENO, 0xFEB1);   ///< PWMA Output enable control
SFRX(PWMA_PS, 0xFEB2);    ///< PWMA Output pin selection register
SFRX(PWMA_IOAUX, 0xFEB3); ///< PWMA Auxiliary register
SFRX(PWMB_ETRPS, 0xFEB4); ///< PWMB ETR Select register
SFRX(PWMB_ENO, 0xFEB5);   ///< PWMB Output enable control
SFRX(PWMB_PS, 0xFEB6);    ///< PWMB Output pin selection register
SFRX(PWMB_IOAUX, 0xFEB7); ///< PWMB Auxiliary register
SFRX(PWMA_CR1, 0xFEC0);   ///< PWMA Control register 1
SFRX(PWMA_CR2, 0xFEC1);   ///< PWMA Control register 2
SFRX(PWMA_SMCR, 0xFEC2);  ///< PWMA Slave mode control
SFRX(PWMA_ETR, 0xFEC3);   ///< PWMA External trigger register
SFRX(PWMA_IER, 0xFEC4);   ///< PWMA Interrupt enable register
SFRX(PWMA_SR1, 0xFEC5);   ///< PWMA Status register 1
SFRX(PWMA_SR2, 0xFEC6);   ///< PWMA Status register 2
SFRX(PWMA_EGR, 0xFEC7);   ///< PWMA Event occurrence register
SFRX(PWMA_CCMR1, 0xFEC8); ///< PWMA Compare mode register 1
SFRX(PWMA_CCMR2, 0xFEC9); ///< PWMA Compare mode register 2
SFRX(PWMA_CCMR3, 0xFECA); ///< PWMA Compare mode register 3
SFRX(PWMA_CCMR4, 0xFECB); ///< PWMA Compare mode register 4
SFRX(PWMA_CCE1, 0xFECC);  ///< PWMA Capture compare enable register 1
SFRX(PWMA_CCE2, 0xFECD);  ///< PWMA Capture compare enable register 2
SFRX(PWMA_CCE3, 0xFECE);  ///< PWMA Capture compare enable register 3
SFRX(PWMA_CCE4, 0xFECF);  ///< PWMA Capture compare enable register 4
SFRX(PWMA_CNTRH, 0xFED0); ///< PWMA Counter high byte
SFRX(PWMA_CNTRL, 0xFED1); ///< PWMA Counter low byte
SFRX(PWMA_PSCRH, 0xFED0); ///< PWMA Prescaler high byte
SFRX(PWMA_PSCRL, 0xFED1); ///< PWMA Prescaler low byte
SFRX(PWMA_ARRH, 0xFED2);  ///< PWMA Auto reload register high byte
SFRX(PWMA_ARRL, 0xFED3);  ///< PWMA Auto reload register low byte
SFRX(PWMA_RCR, 0xFED4);   ///< PWMA Repeat counter register
SFRX(PWMA_CCR1H, 0xFED5); ///< PWMA Compare capture register 1 high bit
SFRX(PWMA_CCR1L, 0xFED6); ///< PWMA Compare capture register 1 low bit
SFRX(PWMA_CCR2H, 0xFED7); ///< PWMA Compare capture register 2 high bit
SFRX(PWMA_CCR2L, 0xFED8); ///< PWMA Compare capture register 2 low bit
SFRX(PWMA_CCR3H, 0xFED9); ///< PWMA Compare capture register 3 high bit
SFRX(PWMA_CCR3L, 0xFEDA); ///< PWMA Compare capture register 3 low bit
SFRX(PWMA_CCR4H, 0xFEDB); ///< PWMA Compare capture register 4 high bit
SFRX(PWMA_CCR4L, 0xFEDC); ///< PWMA Compare capture register 4 low bit
SFRX(PWMA_BKR, 0xFEDD);   ///< PWMA Brake register
SFRX(PWMA_DTR, 0xFEDE);   ///< PWMA Dead zone control register
SFRX(PWMA_OISR, 0xFEDF);  ///< PWMA Output idle status register
SFRX(PWMB_CR1, 0xFEE0);   ///< PWMB Control register 1
SFRX(PWMB_CR2, 0xFEE1);   ///< PWMB Control register 2
SFRX(PWMB_SMCR, 0xFEE2);  ///< PWMB Slave mode control register
SFRX(PWMB_ETR, 0xFEE3);   ///< PWMB External trigger register
SFRX(PWMB_IER, 0xFEE4);   ///< PWMB Interrupt enable register
SFRX(PWMB_SR1, 0xFEE5);   ///< PWMB Status register 1
SFRX(PWMB_SR2, 0xFEE6);   ///< PWMB Status register 2
SFRX(PWMB_EGR, 0xFEE7);   ///< PWMB Event occurrence register
SFRX(PWMB_CCMR1, 0xFEE8); ///< PWMB Compare mode register 1
SFRX(PWMB_CCMR2, 0xFEE9); ///< PWMB Compare mode register 2
SFRX(PWMB_CCMR3, 0xFEEA); ///< PWMB Compare mode register 3
SFRX(PWMB_CCMR4, 0xFEEB); ///< PWMB Compare mode register 4
SFRX(PWMB_CCE1, 0xFEEC);  ///< PWMB Capture compare enable register 1
SFRX(PWMB_CCE2, 0xFEED);  ///< PWMB Capture compare enable register 2
SFRX(PWMB_CNTRH, 0xFEEE); ///< PWMB Counter high byte
SFRX(PWMB_CNTRL, 0xFEEF); ///< PWMB Counter low byte
SFRX(PWMB_PSCRH, 0xFEF0); ///< PWMB Prescaler high byte
SFRX(PWMB_PSCRL, 0xFEF1); ///< PWMB Prescaler low byte
SFRX(PWMB_ARRH, 0xFEF2);  ///< PWMB Auto reload register high byte
SFRX(PWMB_ARRL, 0xFEF3);  ///< PWMB Auto reload register low byte
SFRX(PWMB_RCR, 0xFEF4);   ///< PWMB Repeat counter register
SFRX(PWMB_CCR1H, 0xFEF5); ///< PWMB Compare capture register 1 high bit
SFRX(PWMB_CCR1L, 0xFEF6); ///< PWMB Compare capture register 1 low bit
SFRX(PWMB_CCR2H, 0xFEF7); ///< PWMB Compare capture register 2 high bit
SFRX(PWMB_CCR2L, 0xFEF8); ///< PWMB Compare capture register 2 low bit
SFRX(PWMB_CCR3H, 0xFEF9); ///< PWMB Compare capture register 3 high bit
SFRX(PWMB_CCR3L, 0xFEFA); ///< PWMB Compare capture register 3 low bit
SFRX(PWMB_CCR4H, 0xFEFB); ///< PWMB Compare capture register 4 high bit
SFRX(PWMB_CCR4L, 0xFEFC); ///< PWMB Compare capture register 4 low bit
SFRX(PWMB_BKR, 0xFEFD);   ///< PWMB Brake register
SFRX(PWMB_DTR, 0xFEFE);   ///< PWMB Dead zone control register
SFRX(PWMB_OISR, 0xFEFF);  ///< PWMB Output idle status register
SFRX(MD3, 0xFCF0);        ///< MDU Data register
SFRX(MD2, 0xFCF1);        ///< MDU Data register
SFRX(MD1, 0xFCF2);        ///< MDU Data register
SFRX(MD0, 0xFCF3);        ///< MDU Data register
SFRX(MD5, 0xFCF4);        ///< MDU Data register
SFRX(MD4, 0xFCF5);        ///< MDU Data register
SFRX(ARCON, 0xFCF6);      ///< MDU Mode Control Register
SFRX(OPCON, 0xFCF7);      ///< MDU Operation Control Register
SFRX(P0INTE, 0xFD00);     ///< P0 Interrupt enable register
SFRX(P1INTE, 0xFD01);     ///< P1 Interrupt enable register
SFRX(P2INTE, 0xFD02);     ///< P2 Interrupt enable register
SFRX(P3INTE, 0xFD03);     ///< P3 Interrupt enable register
SFRX(P4INTE, 0xFD04);     ///< P4 Interrupt enable register
SFRX(P5INTE, 0xFD05);     ///< P5 Interrupt enable register
SFRX(P6INTE, 0xFD06);     ///< P6 Interrupt enable register
SFRX(P7INTE, 0xFD07);     ///< P7 Interrupt enable register
SFRX(P0INTF, 0xFD10);     ///< P0 Interrupt flag register
SFRX(P1INTF, 0xFD11);     ///< P1 Interrupt flag register
SFRX(P2INTF, 0xFD12);     ///< P2 Interrupt flag register
SFRX(P3INTF, 0xFD13);     ///< P3 Interrupt flag register
SFRX(P4INTF, 0xFD14);     ///< P4 Interrupt flag register
SFRX(P5INTF, 0xFD15);     ///< P5 Interrupt flag register
SFRX(P6INTF, 0xFD16);     ///< P6 Interrupt flag register
SFRX(P7INTF, 0xFD17);     ///< P7 Interrupt flag register
SFRX(P0IM0, 0xFD20);      ///< P0 Interrupt mode register 0
SFRX(P1IM0, 0xFD21);      ///< P1 Interrupt mode register 0
SFRX(P2IM0, 0xFD22);      ///< P2 Interrupt mode register 0
SFRX(P3IM0, 0xFD23);      ///< P3 Interrupt mode register 0
SFRX(P4IM0, 0xFD24);      ///< P4 Interrupt mode register 0
SFRX(P5IM0, 0xFD25);      ///< P5 Interrupt mode register 0
SFRX(P6IM0, 0xFD26);      ///< P6 Interrupt mode register 0
SFRX(P7IM0, 0xFD27);      ///< P7 Interrupt mode register 0
SFRX(P0IM1, 0xFD30);      ///< P0 Interrupt mode register 1
SFRX(P1IM1, 0xFD31);      ///< P1 Interrupt mode register 1
SFRX(P2IM1, 0xFD32);      ///< P2 Interrupt mode register 1
SFRX(P3IM1, 0xFD33);      ///< P3 Interrupt mode register 1
SFRX(P4IM1, 0xFD34);      ///< P4 Interrupt mode register 1
SFRX(P5IM1, 0xFD35);      ///< P5 Interrupt mode register 1
SFRX(P6IM1, 0xFD36);      ///< P6 Interrupt mode register 1
SFRX(P7IM1, 0xFD37);      ///< P7 Interrupt mode register 1
SFRX(P0WKUE, 0xFD40);     ///< P0 Interrupt Wake-Up Enable Register
SFRX(P1WKUE, 0xFD41);     ///< P1 Interrupt Wake-Up Enable Register
SFRX(P2WKUE, 0xFD42);     ///< P2 Interrupt Wake-Up Enable Register
SFRX(P3WKUE, 0xFD43);     ///< P3 Interrupt Wake-Up Enable Register
SFRX(P4WKUE, 0xFD44);     ///< P4 Interrupt Wake-Up Enable Register
SFRX(P5WKUE, 0xFD45);     ///< P5 Interrupt Wake-Up Enable Register
SFRX(P6WKUE, 0xFD46);     ///< P6 Interrupt Wake-Up Enable Register
SFRX(P7WKUE, 0xFD47);     ///< P7 Interrupt Wake-Up Enable Register
SFRX(PINPL, 0xFD60);      ///< I/O Interrupt Priority Low Register
SFRX(PINPH, 0xFD61);      ///< I/O Interrupt Priority High Register
SFRX(SCON6, 0xFD70);      ///< UART6 Control Register
SFRX(SEGENL, 0xFD80);     ///< SEG Enable Register Low
SFRX(SEGENH, 0xFD81);     ///< SEG Enable Register High
SFRX(LEDCON, 0xFD82);     ///< LED Control Register
SFRX(LEDCTRL, 0xFD83);    ///< LED Control Register
SFRX(TSCHEN1, 0xFB40);    ///< Touch Key Enable Register 1
SFRX(TSCHEN2, 0xFB41);    ///< Touch Key Enable Register 2
SFRX(TSCFG1, 0xFB42);     ///< Touch Key Configuration Register 1
SFRX(TSCFG2, 0xFB43);     ///< Touch Key Configuration Register 2
SFRX(TSWUTC, 0xFB44);     ///< Touch Key Wakeup Control
SFRX(TSCTRL, 0xFB45);     ///< Touch Key Control Register
SFRX(TSSTA1, 0xFB46);     ///< Touch Key Status Register 1
SFRX(TSSTA2, 0xFB47);     ///< Touch Key Status Register 2
SFRX(TSRT, 0xFB48);       ///< Touch Key Time Control Register
SFRX(TSDATH, 0xFB49);     ///< Touch Key Data High Byte
SFRX(TSDATL, 0xFB4A);     ///< Touch Key Data Low Byte
SFRX(TSTH00H, 0xFB50);    ///< Touch Key0 Threshold High Byte
SFRX(TSTH00L, 0xFB51);    ///< Touch Key0 Threshold Low Byte
SFRX(TSTH01H, 0xFB52);    ///< Touch Key1 Threshold High Byte
SFRX(TSTH01L, 0xFB53);    ///< Touch Key1 Threshold Low Byte
SFRX(TSTH02H, 0xFB54);    ///< Touch Key2 Threshold High Byte
SFRX(TSTH02L, 0xFB55);    ///< Touch Key2 Threshold Low Byte
SFRX(TSTH03H, 0xFB56);    ///< Touch Key3 Threshold High Byte
SFRX(TSTH03L, 0xFB57);    ///< Touch Key3 Threshold Low Byte
SFRX(TSTH04H, 0xFB58);    ///< Touch Key4 Threshold High Byte
SFRX(TSTH04L, 0xFB59);    ///< Touch Key4 Threshold Low Byte
SFRX(TSTH05H, 0xFB5A);    ///< Touch Key5 Threshold High Byte
SFRX(TSTH05L, 0xFB5B);    ///< Touch Key5 Threshold Low Byte
SFRX(TSTH06H, 0xFB5C);    ///< Touch Key6 Threshold High Byte
SFRX(TSTH06L, 0xFB5D);    ///< Touch Key6 Threshold Low Byte
SFRX(TSTH07H, 0xFB5E);    ///< Touch Key7 Threshold High Byte
SFRX(TSTH07L, 0xFB5F);    ///< Touch Key7 Threshold Low Byte
SFRX(TSTH08H, 0xFB60);    ///< Touch Key8 Threshold High Byte
SFRX(TSTH08L, 0xFB61);    ///< Touch Key8 Threshold Low Byte
SFRX(TSTH09H, 0xFB62);    ///< Touch Key9 Threshold High Byte
SFRX(TSTH09L, 0xFB63);    ///< Touch Key9 Threshold Low Byte
SFRX(TSTH10H, 0xFB64);    ///< Touch Key10 Threshold High Byte
SFRX(TSTH10L, 0xFB65);    ///< Touch Key10 Threshold Low Byte
SFRX(TSTH11H, 0xFB66);    ///< Touch Key11 Threshold High Byte
SFRX(TSTH11L, 0xFB67);    ///< Touch Key11 Threshold Low Byte
SFRX(TSTH12H, 0xFB68);    ///< Touch Key12 Threshold High Byte
SFRX(TSTH12L, 0xFB69);    ///< Touch Key12 Threshold Low Byte
SFRX(TSTH13H, 0xFB6A);    ///< Touch Key13 Threshold High Byte
SFRX(TSTH13L, 0xFB6B);    ///< Touch Key13 Threshold Low Byte
SFRX(TSTH14H, 0xFB6C);    ///< Touch Key14 Threshold High Byte
SFRX(TSTH14L, 0xFB6D);    ///< Touch Key14 Threshold Low Byte
SFRX(TSTH15H, 0xFB6E);    ///< Touch Key15 Threshold High Byte
SFRX(TSTH15L, 0xFB6F);    ///< Touch Key15 Threshold Low Byte
SFRX(LCDCFG, 0xFB80);     ///< LCD configuration register
SFRX(LCDCFG2, 0xFB81);    ///< LCD configuration register 2
SFRX(DBLEN, 0xFB82);      ///< Dead time length configuration
SFRX(COMLENL, 0xFB83);    ///< COM time length configuration low bit
SFRX(COMLENM, 0xFB84);    ///< COM time length configuration median bit
SFRX(COMLENH, 0xFB85);    ///< COM time length configuration high bit
SFRX(BLINKRATE, 0xFB86);  ///< Flicker rate configuration register
SFRX(LCDCR, 0xFB87);      ///< LCD control register
SFRX(COMON, 0xFB88);      ///< COM Line Enable Register
SFRX(SEGON1, 0xFB8A);     ///< SEG Line Enable Register 1
SFRX(SEGON2, 0xFB8B);     ///< SEG Line Enable Register 2
SFRX(SEGON3, 0xFB8C);     ///< SEG Line Enable Register 3
SFRX(SEGON4, 0xFB8D);     ///< SEG Line Enable Register 4
SFRX(SEGON5, 0xFB8E);     ///< SEG Line Enable Register 5
SFRX(C0SEGV0, 0xFB90);    ///< C0SEG7_0 data register
SFRX(C0SEGV1, 0xFB91);    ///< C0SEG15_8 data register
SFRX(C0SEGV2, 0xFB92);    ///< C0SEG23_16 data register
SFRX(C0SEGV3, 0xFB93);    ///< C0SEG31_24 data register
SFRX(C0SEGV4, 0xFB94);    ///< C0SEG39_32 data register
SFRX(C0SEGV5, 0xFB95);    ///< C0SEG47_40 data register
SFRX(C1SEGV0, 0xFB98);    ///< C1SEG7_0 data register
SFRX(C1SEGV1, 0xFB99);    ///< C1SEG15_8 data register
SFRX(C1SEGV2, 0xFB9A);    ///< C1SEG23_16 data register
SFRX(C1SEGV3, 0xFB9B);    ///< C1SEG31_24 data register
SFRX(C1SEGV4, 0xFB9C);    ///< C1SEG39_32 data register
SFRX(C1SEGV5, 0xFB9D);    ///< C1SEG47_40 data register
SFRX(C2SEGV0, 0xFBA0);    ///< C2SEG7_0 data register
SFRX(C2SEGV1, 0xFBA1);    ///< C2SEG15_8 data register
SFRX(C2SEGV2, 0xFBA2);    ///< C2SEG23_16 data register
SFRX(C2SEGV3, 0xFBA3);    ///< C2SEG31_24 data register
SFRX(C2SEGV4, 0xFBA4);    ///< C2SEG39_32 data register
SFRX(C2SEGV5, 0xFBA5);    ///< C2SEG47_40 data register
SFRX(DMA_M2M_CFG, 0xFA00);      ///< M2M_DMA configuration register
SFRX(DMA_M2M_CR, 0xFA01);       ///< M2M_DMA control register
SFRX(DMA_M2M_STA, 0xFA02);      ///< M2M_DMA status register
SFRX(DMA_M2M_AMT, 0xFA03);      ///< M2M_DMA total bytes to be transferred
SFRX(DMA_M2M_DONE, 0xFA04);     ///< M2M_DMA transfer completed bytes
SFRX(DMA_M2M_TXAH, 0xFA05);     ///< M2M_DMA send address high byte
SFRX(DMA_M2M_TXAL, 0xFA06);     ///< M2M_DMA send address low byte
SFRX(DMA_M2M_RXAH, 0xFA07);     ///< M2M_DMA receive address high byte
SFRX(DMA_M2M_RXAL, 0xFA08);     ///< M2M_DMA receive address low byte
SFRX(DMA_ADC_CFG, 0xFA10);      ///< ADC_DMA configuration register
SFRX(DMA_ADC_CR, 0xFA11);       ///< ADC_DMA control register
SFRX(DMA_ADC_STA, 0xFA12);      ///< ADC_DMA status register
SFRX(DMA_ADC_RXAH, 0xFA17);     ///< ADC_DMA receive address high byte
SFRX(DMA_ADC_RXAL, 0xFA18);     ///< ADC_DMA receive address low byte
SFRX(DMA_ADC_CFG2, 0xFA19);     ///< ADC_DMA configuration register 2
SFRX(DMA_ADC_CHSW0, 0xFA1A);    ///< ADC_DMA channel enable 0
SFRX(DMA_ADC_CHSW1, 0xFA1B);    ///< ADC_DMA channel enable 1
SFRX(DMA_SPI_CFG, 0xFA20);      ///< SPI_DMA configuration register
SFRX(DMA_SPI_CR, 0xFA21);       ///< SPI_DMA control register
SFRX(DMA_SPI_STA, 0xFA22);      ///< SPI_DMA status register
SFRX(DMA_SPI_AMT, 0xFA23);      ///< SPI_DMA total bytes to be transferred
SFRX(DMA_SPI_DONE, 0xFA24);     ///< SPI_DMA transfer completed bytes
SFRX(DMA_SPI_TXAH, 0xFA25);     ///< SPI_DMA send address high byte
SFRX(DMA_SPI_TXAL, 0xFA26);     ///< SPI_DMA send address low byte
SFRX(DMA_SPI_RXAH, 0xFA27);     ///< SPI_DMA receive address high byte
SFRX(DMA_SPI_RXAL, 0xFA28);     ///< SPI_DMA receive address low byte
SFRX(DMA_SPI_CFG2, 0xFA29);     ///< SPI_DMA configuration register 2
SFRX(DMA_UART1_CFG, 0xFA30);    ///< UART1_DMA configuration register
SFRX(DMA_UART1_CR, 0xFA31);     ///< UART1_DMA control register
SFRX(DMA_UART1_STA, 0xFA32);    ///< UART1_DMA status register
SFRX(DMA_UART1_AMT, 0xFA33);    ///< UART1_DMA total bytes to be transferred
SFRX(DMA_UART1_DONE, 0xFA34);   ///< UART1_DMA transfer completed bytes
SFRX(DMA_UART1_TXAH, 0xFA35);   ///< UART1_DMA send address high byte
SFRX(DMA_UART1_TXAL, 0xFA36);   ///< UART1_DMA send address low byte
SFRX(DMA_UART1R_CFG, 0xFA38);    ///< UART1_DMA configuration register
SFRX(DMA_UART1R_CR, 0xFA39);     ///< UART1_DMA control register
SFRX(DMA_UART1R_STA, 0xFA3A);    ///< UART1_DMA status register
SFRX(DMA_UART1R_AMT, 0xFA3B);    ///< UART1_DMA total bytes to be transferred
SFRX(DMA_UART1R_DONE, 0xFA3C);   ///< UART1_DMA transfer completed bytes
SFRX(DMA_UART1R_DONE, 0xFA3C);  ///< UART1R_DMA transfer completed bytes
SFRX(DMA_UART1R_TXAH, 0xFA3D);  ///< UART1R_DMA send address high byte
SFRX(DMA_UART1R_TXAL, 0xFA3E);  ///< UART1R_DMA send address low byte
SFRX(DMA_UART2_CFG, 0xFA40);    ///< UART2_DMA configuration register
SFRX(DMA_UART2_CR, 0xFA41);     ///< UART2_DMA control register
SFRX(DMA_UART2_STA, 0xFA42);    ///< UART2_DMA status register
SFRX(DMA_UART2_AMT, 0xFA43);    ///< UART2_DMA total bytes to be transferred
SFRX(DMA_UART2_DONE, 0xFA44);   ///< UART2_DMA transfer completed bytes
SFRX(DMA_UART2_TXAH, 0xFA45);   ///< UART2_DMA send address high byte
SFRX(DMA_UART2_TXAL, 0xFA46);   ///< UART2_DMA send address low byte
SFRX(DMA_UART2R_CFG, 0xFA48);    ///< UART3_DMA configuration register
SFRX(DMA_UART2R_CR, 0xFA49);     ///< UART3_DMA control register
SFRX(DMA_UART2R_STA, 0xFA4A);    ///< UART3_DMA status register
SFRX(DMA_UART2R_AMT, 0xFA4B);    ///< UART3_DMA total bytes to be transferred
SFRX(DMA_UART2R_DONE, 0xFA4C);   ///< UART3_DMA transfer completed bytes
SFRX(DMA_UART2R_TXAH, 0xFA4D);   ///< UART3_DMA send address high byte
SFRX(DMA_UART2R_TXAL, 0xFA4E);   ///< UART3_DMA send address low byte
SFRX(DMA_UART3_CFG, 0xFA50);    ///< UART4_DMA configuration register
SFRX(DMA_UART3_CR, 0xFA51);     ///< UART4_DMA control register
SFRX(DMA_UART3_STA, 0xFA52);    ///< UART4_DMA status register
SFRX(DMA_UART3_AMT, 0xFA53);    ///< UART4_DMA total bytes to be transferred
SFRX(DMA_UART3_DONE, 0xFA54);   ///< UART4_DMA transfer completed bytes
SFRX(DMA_UART3_TXAH, 0xFA55);   ///< UART4_DMA send address high byte
SFRX(DMA_UART3_TXAL, 0xFA56);   ///< UART4_DMA send address low byte
SFRX(DMA_UART3R_CFG, 0xFA58);   ///< UART3R_DMA configuration register
SFRX(DMA_UART3R_CR, 0xFA59);    ///< UART3R_DMA control register
SFRX(DMA_UART3R_STA, 0xFA5A);   ///< UART3R_DMA status register
SFRX(DMA_UART3R_AMT, 0xFA5B);   ///< UART3R_DMA total bytes to be transferred
SFRX(DMA_UART3R_DONE, 0xFA5C);  ///< UART3R_DMA transfer completed bytes
SFRX(DMA_UART3R_TXAH, 0xFA5D);  ///< UART3R_DMA send address high byte
SFRX(DMA_UART3R_TXAL, 0xFA5E);  ///< UART3R_DMA send address low byte
SFRX(DMA_UART4_CFG, 0xFA60);    ///< UART4_DMA configuration register
SFRX(DMA_UART4_CR, 0xFA61);     ///< UART4_DMA control register
SFRX(DMA_UART4_STA, 0xFA62);    ///< UART4_DMA status register
SFRX(DMA_UART4_AMT, 0xFA63);    ///< UART4_DMA total bytes to be transferred
SFRX(DMA_UART4_DONE, 0xFA64);   ///< UART4_DMA transfer completed bytes
SFRX(DMA_UART4_TXAH, 0xFA65);   ///< UART4_DMA send address high byte
SFRX(DMA_UART4_TXAL, 0xFA66);   ///< UART4_DMA send address low byte
SFRX(DMA_UART4R_CFG, 0xFA68);   ///< UART4R_DMA configuration register
SFRX(DMA_UART4R_CR, 0xFA69);    ///< UART4R_DMA control register
SFRX(DMA_UART4R_STA, 0xFA6A);   ///< UART4R_DMA status register
SFRX(DMA_UART4R_AMT, 0xFA6B);   ///< UART4R_DMA total bytes to be transferred
SFRX(DMA_UART4R_DONE, 0xFA6C);  ///< UART4R_DMA transfer completed bytes
SFRX(DMA_UART4R_TXAH, 0xFA6D);  ///< UART4R_DMA send address high byte
SFRX(DMA_UART4R_TXAL, 0xFA6E);  ///< UART4R_DMA send address low byte
SFRX(DMA_LCM_CFG, 0xFA70);      ///< LCM_DMA configuration register
SFRX(DMA_LCM_CR, 0xFA71);       ///< LCM_DMA control register
SFRX(DMA_LCM_STA, 0xFA72);      ///< LCM_DMA status register
SFRX(DMA_LCM_AMT, 0xFA73);      ///< LCM_DMA total bytes to be transferred
SFRX(DMA_LCM_DONE, 0xFA74);     ///< LCM_DMA transfer completed bytes
SFRX(DMA_LCM_TXAH, 0xFA75);     ///< LCM_DMA send address high byte
SFRX(DMA_LCM_TXAL, 0xFA76);     ///< LCM_DMA send address low byte
SFRX(DMA_LCM_RXAH, 0xFA77);     ///< LCM_DMA receive address high byte
SFRX(DMA_LCM_RXAL, 0xFA78);     ///< LCM_DMA receive address low byte

/******************************************************************************\
 * Public functions
\******************************************************************************/

// Define SFRs for port mode registers
#endif // STC8H1_H