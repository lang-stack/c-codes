#include <stdio.h>
#include <stdint.h>

uint64_t square(uint8_t index);
uint64_t total(void);

int main() {
	printf("%llu\n", total());
	return 0;
}

uint64_t square(uint8_t index) {
	if(index == 0 || index > 64) {
		return 0;
	}

	return 1ULL << (index - 1);
}

uint64_t total(void) {
	const uint8_t total_squares = 64;
	uint64_t sum = 0;

	for(uint8_t i = 1; i <= total_squares; i++) {
		sum += square(i);
	}

	return sum;
}