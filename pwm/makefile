gamma: gamma.c
	avr-gcc -O1 -DF_CPU=16500000 -mmcu=attiny85 gamma.c -o gamma
	avr-objcopy gamma -O ihex gamma.hex

gamma.hex: gamma
	avr-objcopy gamma -O ihex gamma.hex

flash: gamma gamma.hex
	/Users/jonathantaylor/Library/Arduino15/packages/digistump/tools/micronucleus/2.0a4/micronucleus --run gamma.hex

.PHONY: clean
clean: 
	rm  -f gamma gamma.hex

