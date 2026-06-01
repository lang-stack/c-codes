#include <stdio.h>

unsigned int sum_of_squares(unsigned int number);
unsigned int square_of_sum(unsigned int number);
unsigned int difference_of_squares(unsigned int number);

int main() {
	unsigned int number = 10;

	printf("sum of squares : %u\n", sum_of_squares(number));
	printf("square of sum : %u\n", square_of_sum(number));
	printf("square difference : %u\n", difference_of_squares(number));

	return 0;
}

unsigned int sum_of_squares(unsigned int number) {
	unsigned int sum = 0;

	for(unsigned int i = 1; i <= number; i++) {
		sum += i * i;
	}

	return sum;
}

unsigned int square_of_sum(unsigned int number) {
	unsigned int sum = 0;

	for(unsigned int i = 0; i <= number; i++) {
		sum += i;
	}

	return sum * sum;
}

unsigned int difference_of_squares(unsigned int number) {
	unsigned int sumofsquares = sum_of_squares(number);
	unsigned int squareofsum = square_of_sum(number);

	return squareofsum - sumofsquares;
}