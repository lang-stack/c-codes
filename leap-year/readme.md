# Leap Year Checker

## 1. Problem Statement

Write a C program that determines whether a given year is a leap year.

A leap year follows these rules:

1. If the year is divisible by 400, it is a leap year.
2. If the year is divisible by 100 but not by 400, it is not a leap year.
3. If the year is divisible by 4 but not by 100, it is a leap year.
4. Otherwise, it is not a leap year.

The program should:

* Accept a year as input from the user.
* Validate that input was successfully read.
* Display whether the year is a leap year or not.

---

## 2. Program

```c
#include <stdio.h>

int isLeapYear(int year);

int main() {
    int year;

    if (scanf("%d", &year) != 1) {
        return 1;
    }

    if (isLeapYear(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}

int isLeapYear(int year) {
    return (year % 400 == 0) ||
           ((year % 4 == 0) && (year % 100 != 0));
}
```

---

## 3. Program Stats

### Difficulty Level

Beginner

### Concepts Used

* Functions
* Function Prototypes
* Integer Variables
* User Input (`scanf`)
* Output (`printf`)
* Conditional Logic
* Logical Operators
* Modulo Operator (`%`)
* Return Values

### Time Complexity

O(1)

Reason:
The program performs a fixed number of arithmetic operations regardless of input size.

### Space Complexity

O(1)

Reason:
Only one integer variable is stored.

### Program Type

Decision-Making Program

The program evaluates a condition and returns one of two possible outcomes.

---

## 4. What Still Needs Improvement

### 1. Use Boolean Type

Current:

```c
int isLeapYear(int year);
```

Future Improvement:

```c
#include <stdbool.h>

bool isLeapYear(int year);
```

Using `bool` makes the function's purpose clearer.

---

### 2. Input Validation Message

Current:

```c
if (scanf("%d", &year) != 1) {
    return 1;
}
```

Improvement:

```c
if (scanf("%d", &year) != 1) {
    printf("Invalid input.\n");
    return 1;
}
```

This gives feedback to the user.

---

### 3. Range Validation

The program currently accepts:

```text
-500
100000000
```

You may want to define what range of years is considered valid.

---

### 4. User Prompt

Current:

```c
scanf("%d", &year);
```

Improvement:

```c
printf("Enter a year: ");
```

This makes the program easier for users to interact with.

---

## 5. Example Inputs and Outputs

### Example 1

Input:

```text
2024
```

Output:

```text
2024 is a leap year.
```

---

### Example 2

Input:

```text
2023
```

Output:

```text
2023 is not a leap year.
```

---

### Example 3

Input:

```text
2000
```

Output:

```text
2000 is a leap year.
```

---

### Example 4

Input:

```text
1900
```

Output:

```text
1900 is not a leap year.
```

---

### Example 5

Input:

```text
abcd
```

Output:

```text
Program exits with error code 1.
```

---

## 6. Things Learned In This Program

### 1. Function Prototypes

A function prototype tells the compiler that a function exists before it is used.

Example:

```c
int isLeapYear(int year);
```

Without a prototype, the compiler may not know how the function should be called.

---

### 2. Functions

Functions help divide a program into smaller reusable parts.

Example:

```c
int isLeapYear(int year)
```

Benefits:

* Better organization
* Reusability
* Easier testing
* Easier maintenance

---

### 3. Modulo Operator (%)

The modulo operator returns the remainder after division.

Examples:

```c
10 % 2 = 0
10 % 3 = 1
```

Used to check divisibility.

Example:

```c
year % 4 == 0
```

Means the year is divisible by 4.

---

### 4. Logical AND (&&)

Both conditions must be true.

Example:

```c
(year % 4 == 0) && (year % 100 != 0)
```

Meaning:

* Divisible by 4
* Not divisible by 100

Both must be true.

---

### 5. Logical OR (||)

At least one condition must be true.

Example:

```c
(year % 400 == 0) ||
((year % 4 == 0) && (year % 100 != 0))
```

Either rule can make the year a leap year.

---

### 6. Input Validation

`scanf()` returns the number of successfully read values.

Example:

```c
scanf("%d", &year)
```

Possible returns:

```c
1
```

Input successfully read.

```c
0
```

Invalid input.

Checking the return value prevents invalid data from entering the program.

---

### 7. Returning Expressions Directly

Instead of:

```c
if (condition) {
    return 1;
}

return 0;
```

You can write:

```c
return condition;
```

This is shorter and commonly used in C.

---

### 8. Separation of Responsibilities

`main()` handles:

* User interaction
* Input
* Output

`isLeapYear()` handles:

* Leap year calculation

This is a fundamental programming principle called Separation of Concerns.

It makes programs easier to maintain and extend.

---

## Mentor Assessment

### Strengths

* Good function decomposition.
* Correct leap year logic.
* Proper use of logical operators.
* Input validation present.
* Readable and concise code.

### Weaknesses

* Minimal user interaction.
* No year range validation.
* Not yet using C's boolean type.
* Program is small and does not yet demonstrate mastery of loops, arrays, structs, pointers, or file handling.

### Skill Level After This Program

Strong Beginner

You understand basic program structure and conditional logic. The next major areas to learn are loops, arrays, pointers, structs, and memory management.
