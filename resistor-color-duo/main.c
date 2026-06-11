#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
	BLACK,
	BROWN,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	VIOLET,
	GREY,
	WHITE
} resistor_band_t;

int color_code(resistor_band_t colors_array[]);

int main(void) {
	resistor_band_t bands[] = { BLACK, BROWN };
	printf("%d\n", color_code(bands));
	return 0;
}

int color_code(resistor_band_t colors_array[]) {
	return (colors_array[0] * 10) + colors_array[1];
}