#include <stdio.h>

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

int color_code(resistor_band_t color);
const resistor_band_t *colors(void);

int main(void) {
	printf("%d", color_code(GREY));
	return 0;
}

int color_code(resistor_band_t color) {
	return color;
}

const resistor_band_t *colors(void) {
	static const resistor_band_t bands[] = {
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
	};

	return bands;
}