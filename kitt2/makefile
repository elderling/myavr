kitt: kitt.c light_ws2812.c
	avr-gcc -O1 -DF_CPU=16500000 -mmcu=attiny85 light_ws2812.c kitt.c -o kitt
	avr-objcopy kitt -O ihex kitt.hex


kitt.hex: kitt
	avr-objcopy kitt -O ihex kitt.hex

flash: kitt kitt.hex
	/Users/jonathantaylor/Library/Arduino15/packages/digistump/tools/micronucleus/2.0a4/micronucleus --run kitt.hex

.PHONY: clean
clean: 
	rm  -f kitt kitt.hex

