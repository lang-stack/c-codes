#include <stdio.h>
#include <stdbool.h>

bool is_even(int num);

int steps(int start);

int main(void) {
	int num;
	if(scanf("%d", &num) != 1) {
		return -1;
	}

	if(num <= 0) {
		return -1;
	}

	printf("Total steps : %d\n", steps(num));
	return 0;
}

int steps(int start) {
	if(start <= 0) {
		return -1;
	}
	
	int totalSteps = 0;
	int num = start;

	while(num != 1) {
		if(is_even(num)) {
			num = (num / 2);
		} else {
			num = (num * 3) + 1;
		}

		totalSteps += 1;
	}

	return totalSteps;
}

bool is_even(int num) {
	return (num % 2 == 0);
}