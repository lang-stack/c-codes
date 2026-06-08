# Collatz Conjecture

---

# 1. Problem Statement

Given a positive integer, repeatedly apply the following rules until the number becomes `1`:

### Rule 1: Even Numbers

If the number is even:

```text
n / 2
```

### Rule 2: Odd Numbers

If the number is odd:

```text
3 × n + 1
```

Count how many transformations are performed before reaching `1`.

---

### Example

Starting number:

```text
12
```

Sequence:

```text
12 → 6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1
```

Transformations:

```text
12 → 6   (1)
6 → 3    (2)
3 → 10   (3)
10 → 5   (4)
5 → 16   (5)
16 → 8   (6)
8 → 4    (7)
4 → 2    (8)
2 → 1    (9)
```

Result:

```text
9 steps
```

---

# 2. Your Program

```c
#include <stdio.h>
#include <stdbool.h>

bool is_even(int num);

int steps(int start);

int main(void) {
	int num;
	if(scanf("%d", &num) != 1) {
		return 1;
	}

	if(num <= 0) {
		return 1;
	}

	printf("Total steps : %d\n", steps(num));
	return 0;
}

int steps(int start) {
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
```

---

# 3. Improved Version of the Program

```c
#include <stdbool.h>

bool is_even(int num);

int steps(int start);

int steps(int start)
{
    if (start <= 0) {
        return -1;
    }

    int step_count = 0;
    int num = start;

    while (num != 1) {
        if (is_even(num)) {
            num = num / 2;
        } else {
            num = num * 3 + 1;
        }

        step_count++;
    }

    return step_count;
}

bool is_even(int num)
{
    return num % 2 == 0;
}
```

### Improvements

1. Validation moved into `steps()`.
2. Cleaner variable naming.
3. Removed unnecessary parentheses.
4. Function is safer if called from another part of the program.

---

# 4. Example Inputs and Outputs

---

## Example 1

Input:

```text
1
```

Sequence:

```text
1
```

Output:

```text
0
```

Explanation:

Already at the destination.

---

## Example 2

Input:

```text
2
```

Sequence:

```text
2 → 1
```

Output:

```text
1
```

---

## Example 3

Input:

```text
3
```

Sequence:

```text
3 → 10 → 5 → 16 → 8 → 4 → 2 → 1
```

Output:

```text
7
```

---

## Example 4

Input:

```text
12
```

Sequence:

```text
12 → 6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1
```

Output:

```text
9
```

---

## Example 5

Input:

```text
16
```

Sequence:

```text
16 → 8 → 4 → 2 → 1
```

Output:

```text
4
```

---

# 5. Things Learned

---

# The Collatz Conjecture

The Collatz Conjecture states:

> Starting with any positive integer and repeatedly applying the Collatz rules will eventually reach 1.

Examples:

```text
1 → 1
2 → 1
3 → 10 → 5 → 16 → 8 → 4 → 2 → 1
12 → ... → 1
```

Despite being simple to describe, nobody has proven it for all positive integers.

---

# Header File: stdbool.h

```c
#include <stdbool.h>
```

Provides:

```c
bool
true
false
```

Without it:

```c
int is_even(int num);
```

With it:

```c
bool is_even(int num);
```

The second version communicates intent more clearly.

---

# Functions

Your program uses two functions:

```c
bool is_even(int num);
```

and

```c
int steps(int start);
```

---

## Why Functions Exist

Functions break a problem into smaller tasks.

Instead of:

```c
main()
{
    ...
    ...
    ...
}
```

you separate responsibilities.

---

### is_even()

Responsibility:

```text
Determine whether a number is even.
```

Implementation:

```c
bool is_even(int num)
{
    return (num % 2 == 0);
}
```

Examples:

```text
is_even(2)  → true
is_even(10) → true
is_even(7)  → false
```

---

### steps()

Responsibility:

```text
Calculate how many Collatz transformations are required.
```

---

# Modulus Operator (%)

Operator:

```c
%
```

Returns the remainder after division.

Examples:

```c
6 % 2
```

Result:

```text
0
```

---

```c
7 % 2
```

Result:

```text
1
```

---

Even numbers always produce:

```text
0
```

when divided by 2.

Therefore:

```c
num % 2 == 0
```

means:

```text
Number is even.
```

---

# Variable Initialization

```c
int totalSteps = 0;
```

Purpose:

```text
Count how many transformations occur.
```

---

```c
int num = start;
```

Purpose:

```text
Store a working copy of the number.
```

This prevents modification of the original parameter.

---

# While Loops

Your loop:

```c
while(num != 1)
{
    ...
}
```

Meaning:

```text
Keep executing while the number is not 1.
```

---

### Why While Instead of For?

A `for` loop is useful when the number of iterations is known.

Example:

```c
for(int i = 0; i < 10; i++)
```

You know it runs 10 times.

---

For Collatz:

```text
How many steps will 12 take?
Unknown

How many steps will 27 take?
Unknown

How many steps will 1000 take?
Unknown
```

Therefore:

```c
while(num != 1)
```

is the natural choice.

---

# Algorithm Trace

Let's trace:

```text
start = 6
```

Initial state:

```text
num = 6
steps = 0
```

---

Iteration 1:

```text
6 is even
6 / 2 = 3
steps = 1
```

---

Iteration 2:

```text
3 is odd
3 × 3 + 1 = 10
steps = 2
```

---

Iteration 3:

```text
10 is even
10 / 2 = 5
steps = 3
```

---

Continue:

```text
5 → 16
16 → 8
8 → 4
4 → 2
2 → 1
```

Final:

```text
steps = 8
```

---

# Input Validation

Your program checks:

```c
if(num <= 0)
{
    return 1;
}
```

This prevents invalid inputs.

Examples:

```text
0
-5
-100
```

These are not positive integers.

---

# Increment Operator

You used:

```c
totalSteps += 1;
```

Equivalent to:

```c
totalSteps = totalSteps + 1;
```

---

Many C programmers write:

```c
totalSteps++;
```

which means:

```text
Increase by one.
```

---

# Program Flow

```text
User enters number
        ↓
Validate input
        ↓
Call steps()
        ↓
Loop until number becomes 1
        ↓
Apply Collatz rule
        ↓
Count step
        ↓
Return step count
        ↓
Print result
```

---

# 6. What Still Needs Improvement

### 1. Integer Overflow Awareness

Consider:

```c
num = num * 3 + 1;
```

Large values may exceed the range of `int`.

Future topic:

```c
int64_t
uint64_t
```

---

### 2. Arrays

You have now worked with:

* Variables
* Functions
* Loops

Next important topic:

```text
Arrays
```

---

### 3. Pointers

Not yet demonstrated.

Future topics:

```c
*
&
```

---

### 4. Function Ownership

Think more about:

```text
Where should validation happen?
```

Inside `main()`?

Inside `steps()`?

Both?

This is part of software design.

---

# 7. Mentor Notes

### Strengths

* Correct understanding of the problem.
* Chose the appropriate loop.
* Good function decomposition.
* Correct step counting.
* Proper use of boolean return values.
* Input validation included.

---

### Common Mistakes You Avoided

#### Infinite Loop

Wrong:

```c
while(true)
```

without an exit condition.

You correctly used:

```c
while(num != 1)
```

---

#### Incorrect Step Counting

Some beginners count numbers in the sequence.

You correctly counted transformations.

---

#### Duplicating Logic

You created:

```c
is_even()
```

instead of repeating:

```c
num % 2 == 0
```

everywhere.

---

### Main Lesson

This exercise is not really about the Collatz Conjecture.

The real lessons are:

```text
Conditionals
Loops
Counters
Functions
Boolean logic
Algorithm tracing
Input validation
```

The Collatz sequence is simply a vehicle used to teach those programming concepts.

---

# Personal Mentor Assessment

```text
Functions          : Beginner+
Loops              : Strong Beginner
Integer Types      : Strong Beginner
Enums              : Beginner+
Problem Solving    : Beginner+
Bitwise Thinking   : Beginner
Arrays             : Beginner
Pointers           : Not Demonstrated
Strings            : Not Demonstrated
Structs            : Not Demonstrated
Dynamic Memory     : Not Demonstrated
Memory Lifetime    : Beginner
Input Validation   : Beginner+
```

### Current Observation

You're increasingly writing programs that reflect the problem statement directly:

```text
Problem
    ↓
Function
    ↓
Loop
    ↓
Result
```

That's a stronger habit than memorizing syntax. The next major milestone is becoming comfortable with arrays and pointers, because they are foundational to almost everything else in C.
