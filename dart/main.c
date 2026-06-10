#include <stdio.h>
#include <stdint.h>

typedef struct {
	float x;
	float y;
} coordinate_t;

float square(float point);
uint8_t score(coordinate_t landing_position);

int main(void) {
	coordinate_t landing_position = { 3.0F, 4.0F };
	printf("%d\n", score(landing_position));
}

uint8_t score(coordinate_t landing_position) {
	float distance = square(landing_position.x) + square(landing_position.y);

	if(distance <= 1.0F) {
		return 10;
	}

	if(distance <= 25.0F) {
		return 5;
	}

	if(distance <= 100.0F) {
		return 1;
	}

	return 0;
}

float square(float point) {
	return point * point;
}