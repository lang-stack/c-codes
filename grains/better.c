#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define TOTAL_SQUARES 64

uint64_t square(uint8_t index);
uint64_t total(void);

int main() {
	printf("%" PRIu64 "\n", total());
	return 0;
}

uint64_t square(uint8_t index) {
	if(index == 0 || index > TOTAL_SQUARES) {
		return 0;
	}

	return 1ULL << (index - 1);
}

uint64_t total(void) {
	uint64_t sum = 0;

	for(uint8_t i = 1; i <= TOTAL_SQUARES; i++) {
		sum += square(i);
	}

	return sum;
}