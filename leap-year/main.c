#include <stdio.h>

int isLeapYear(int year);

int main() {
	int year;
	if(scanf("%d", &year) <= 0) {
		return 1;
	}

	if(isLeapYear(year)) {
		printf("%d is a leap year.\n", year);
	} else {
		printf("%d is not a leap year.\n", year);
	}

	return 0;
}

int isLeapYear(int year) {
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}