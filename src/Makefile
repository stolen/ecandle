STCGAL=.venv/bin/stcgal

all: candle.hex

flash: all $(STCGAL)
	$(STCGAL) -a candle.hex -t 24000

%.rel: %.c
	sdcc -mmcs51 --Werror --std-c2x --out-fmt-ihx --opt-code-size --fomit-frame-pointer -c $< -o $@

%.hex: %.c
	sdcc -mmcs51 --Werror --std-c2x --out-fmt-ihx --opt-code-size --fomit-frame-pointer $< -o $@

$(STCGAL):
	python3 -m venv .venv
	bash -c ". .venv/bin/activate && pip install stcgal"
