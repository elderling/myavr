icicle: icicle.c light_ws2812.c ws2812_config.h
	avr-gcc -O1 -DF_CPU=16500000 -mmcu=attiny85 light_ws2812.c icicle.c -o icicle
	avr-objcopy icicle -O ihex icicle.hex


icicle.hex: icicle
	avr-objcopy icicle -O ihex icicle.hex

flash: icicle icicle.hex
	#/Users/jonathantaylor/Library/Arduino15/packages/digistump/tools/micronucleus/2.0a4/micronucleus --run icicle.hex
	micronucleus --run icicle.hex

.PHONY: clean
clean: 
	rm  -f icicle icicle.hex

