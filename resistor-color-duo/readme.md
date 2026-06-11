# Resistor Color Duo

## 1. Problem Statement

Electronic resistors use colored bands to represent their resistance values.

Each color corresponds to a digit:

| Color  | Value |
| ------ | ----- |
| BLACK  | 0     |
| BROWN  | 1     |
| RED    | 2     |
| ORANGE | 3     |
| YELLOW | 4     |
| GREEN  | 5     |
| BLUE   | 6     |
| VIOLET | 7     |
| GREY   | 8     |
| WHITE  | 9     |

The first two color bands form a two-digit number.

Examples:

```text
BROWN GREEN
```

↓

```text
1 5
```

↓

```text
15
```

---

```text
RED BLACK
```

↓

```text
2 0
```

↓

```text
20
```

If more than two colors are provided, only the first two are considered.

Example:

```text
BROWN GREEN VIOLET
```

Result:

```text
15
```

The third color is ignored.

---

## 2. Your Program

```c
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

int color_code(resistor_band_t colors_array[]);

int main(void) {
    resistor_band_t bands[] = { BLACK, BROWN };

    printf("%d\n", color_code(bands));

    return 0;
}

int color_code(resistor_band_t colors_array[]) {
    return (colors_array[0] * 10) + colors_array[1];
}
```

---

## 3. How the Solution Works

### Step 1: Receive the Colors

Example:

```c
resistor_band_t bands[] = {
    BROWN,
    GREEN
};
```

Memory:

```text
Index   Value

0       BROWN
1       GREEN
```

---

### Step 2: Convert Colors to Digits

Because enums are integers:

```text
BROWN = 1
GREEN = 5
```

The compiler automatically stores:

```text
Index   Value

0       1
1       5
```

---

### Step 3: Build the Two-Digit Number

Formula:

```c
(first_digit * 10) + second_digit
```

Example:

```c
(1 * 10) + 5
```

Result:

```text
15
```

---

## 4. Example Inputs and Outputs

### Example 1

Input:

```c
{ BROWN, GREEN }
```

Calculation:

```text
(1 * 10) + 5
```

Output:

```text
15
```

---

### Example 2

Input:

```c
{ RED, BLACK }
```

Calculation:

```text
(2 * 10) + 0
```

Output:

```text
20
```

---

### Example 3

Input:

```c
{ YELLOW, VIOLET }
```

Calculation:

```text
(4 * 10) + 7
```

Output:

```text
47
```

---

### Example 4

Input:

```c
{ BLACK, BROWN }
```

Calculation:

```text
(0 * 10) + 1
```

Output:

```text
1
```

Note:

```text
01
```

and

```text
1
```

represent the same integer value.

---

## 5. Things Learned

### Enums

You used an enum to represent resistor colors:

```c
typedef enum {
    BLACK,
    BROWN,
    RED,
    ...
} resistor_band_t;
```

The compiler assigns values automatically:

```text
BLACK = 0
BROWN = 1
RED = 2
...
```

This allows colors to be used directly as numbers.

---

### Arrays

You stored multiple resistor colors in an array:

```c
resistor_band_t bands[] = {
    BLACK,
    BROWN
};
```

Accessing values:

```c
bands[0]
bands[1]
```

---

### Function Parameters

The function accepts an array:

```c
int color_code(resistor_band_t colors_array[])
```

Inside the function:

```text
colors_array[0]
```

refers to the first color.

```text
colors_array[1]
```

refers to the second color.

---

### Arithmetic Construction

Instead of converting numbers to strings:

```text
1 → "1"
5 → "5"
"15" → 15
```

you used arithmetic:

```c
(1 * 10) + 5
```

which is simpler and more efficient.

---

## 6. What Still Needs Improvement

### Array Lengths

Earlier you attempted:

```c
sizeof(colors_array) / sizeof(colors_array[0])
```

inside the function.

This does not work because function parameters declared as arrays become pointers.

Important rule:

```text
Arrays know their size.
Pointers do not.
```

---

### Const Correctness

The function does not modify the colors.

A future improvement would be:

```c
int color_code(const resistor_band_t colors[])
```

which communicates that the array is read-only.

---

### Understanding Array Decay

This function parameter:

```c
resistor_band_t colors[]
```

is treated by the compiler as:

```c
resistor_band_t *colors
```

Learning why this happens is an important next step.

---

## 7. Mentor Notes

This exercise looks like a resistor problem, but the real lesson is about data representation.

At first it is tempting to think:

```text
BROWN GREEN
```

should become:

```text
"15"
```

using strings.

However, the enum values are already numeric:

```text
BROWN = 1
GREEN = 5
```

which means the answer can be calculated directly:

```c
(1 * 10) + 5
```

No strings are required.

---

### Key Insight

The most important realization from this exercise is:

```text
Not every sequence of digits is a string.
```

If the desired result is a number, keep it as a number and use arithmetic.

---

## Mentor Assessment

```text
Functions              : Beginner+
Loops                  : Strong Beginner
Integer Types          : Beginner+
Enums                  : Beginner+
Structs                : Beginner+
Arrays                 : Beginner
Problem Solving        : Intermediate Beginner
Floating Point         : Beginner+
Pointers               : Emerging
Strings                : Beginner
Dynamic Memory         : Not Demonstrated
```

### Main Lesson

```text
enum → integer → arithmetic
```

is often better than:

```text
enum → string → integer
```

Choosing the simplest representation is one of the most valuable programming skills you can develop.
