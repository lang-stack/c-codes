# Difference of Squares

## 1. Problem Statement

Write a C program that calculates the difference between:

### Sum of Squares

The sum of the squares of the first `N` natural numbers.

Example for `N = 10`:

```text
1² + 2² + 3² + ... + 10²
= 385
```

### Square of Sum

The square of the sum of the first `N` natural numbers.

Example for `N = 10`:

```text
(1 + 2 + 3 + ... + 10)²
= 55²
= 3025
```

### Difference of Squares

The difference between the Square of Sum and the Sum of Squares.

```text
3025 - 385
= 2640
```

The program should calculate all three values.

---

## 2. Program

```c
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
```

---

## 3. Example Inputs and Outputs

### Example 1

Input:

```text
10
```

Output:

```text
sum of squares : 385
square of sum : 3025
square difference : 2640
```

---

### Example 2

Input:

```text
5
```

Output:

```text
sum of squares : 55
square of sum : 225
square difference : 170
```

---

### Example 3

Input:

```text
1
```

Output:

```text
sum of squares : 1
square of sum : 1
square difference : 0
```

---

### Example 4

Input:

```text
0
```

Output:

```text
sum of squares : 0
square of sum : 0
square difference : 0
```

---

## 4. Things Learned

### Function Prototypes

A function prototype tells the compiler about a function before it is used.

Example:

```c
unsigned int sum_of_squares(unsigned int number);
```

Benefits:

* Prevents compilation errors.
* Allows functions to be defined after `main()`.
* Improves code organization.

---

### Functions

The program is divided into three functions:

```c
sum_of_squares()
square_of_sum()
difference_of_squares()
```

Benefits:

* Reusable code.
* Easier debugging.
* Easier maintenance.
* Clear separation of responsibilities.

---

### For Loops

Used to repeat a block of code a fixed number of times.

Example:

```c
for(unsigned int i = 1; i <= number; i++)
```

Loop structure:

```c
for(initialization; condition; update)
```

Execution order:

1. Initialization
2. Condition check
3. Execute loop body
4. Update variable
5. Repeat until condition becomes false

---

### Accumulator Pattern

An accumulator stores a running total.

Example:

```c
unsigned int sum = 0;
```

```c
sum += i;
```

or

```c
sum += i * i;
```

This pattern is frequently used for:

* Totals
* Counts
* Averages
* Statistical calculations

---

### Arithmetic Operators

#### Multiplication

```c
i * i
```

Calculates the square of a number.

Examples:

```text
2 * 2 = 4
5 * 5 = 25
10 * 10 = 100
```

---

### Unsigned Integers

The program uses:

```c
unsigned int
```

Characteristics:

* Stores only non-negative values.
* Provides a larger positive range than a signed integer of the same size.
* Useful when negative values are not expected.

Examples:

```text
0
1
10
100
```

---

### Function Reuse

The function:

```c
difference_of_squares()
```

uses the results of:

```c
sum_of_squares()
square_of_sum()
```

instead of recalculating everything.

Benefits:

* Less duplicated code.
* Easier maintenance.
* Reduced chance of introducing bugs.

---

### Correct Format Specifier

The program prints unsigned integers using:

```c
%u
```

Example:

```c
printf("%u\n", value);
```

This matches the data type:

```c
unsigned int
```

and avoids undefined or incorrect output.

---

## 5. What Still Needs Improvement

### 1. Accept User Input

Currently:

```c
unsigned int number = 10;
```

The value is hardcoded.

Improvement:

```c
unsigned int number;

scanf("%u", &number);
```

This allows the user to choose the value.

---

### 2. Input Validation

If user input is added later, the return value of `scanf()` should be checked.

Example:

```c
if(scanf("%u", &number) != 1) {
    return 1;
}
```

This prevents invalid input from being processed.

---

### 3. Loop Consistency

In `square_of_sum()`:

```c
for(unsigned int i = 0; i <= number; i++)
```

works correctly because adding zero has no effect.

However:

```c
for(unsigned int i = 1; i <= number; i++)
```

would be more consistent with the mathematical definition:

```text
1 + 2 + 3 + ... + N
```

---

### 4. Variable Naming

Current:

```c
sumofsquares
squareofsum
```

More readable alternatives:

```c
sum_of_squares_result
square_of_sum_result
```

or

```c
sum_squares
square_sum
```

---

### 5. Integer Overflow Awareness

For very large values of `number`, calculations may exceed the capacity of `unsigned int`.

Future solutions may require:

```c
unsigned long long
```

or overflow checks.

---

## 6. Mentor Notes

### Strengths

* Program is logically correct.
* Good function decomposition.
* Functions have clear responsibilities.
* Proper use of loops and accumulators.
* Correct use of unsigned integer format specifiers.
* Removed unnecessary condition checks from previous versions.

---

### Weaknesses

* Program still relies on a hardcoded value.
* Variable naming can be improved.
* Loop style is slightly inconsistent.
* No user interaction or input validation yet.

---

### Biggest Lesson From This Program

Before writing code, verify the problem manually.

Example:

For `N = 3`:

```text
Sum of Squares

1² + 2² + 3²
= 1 + 4 + 9
= 14
```

```text
Square of Sum

(1 + 2 + 3)²
= 6²
= 36
```

```text
Difference

36 - 14
= 22
```

Working through a small example by hand makes it easier to translate the problem into correct code.

---

### Recommended Next Topic

Arrays.

Suggested exercises:

1. Sum of Array Elements
2. Average of Numbers in an Array
3. Find Largest Element
4. Find Smallest Element
5. Count Even and Odd Numbers

These will build the foundation needed for strings, pointers, and structs.
