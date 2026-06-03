# Resistor Color

---

# 1. Problem Statement

Electronic resistors use colored bands instead of printing numbers directly on the resistor.

Each color corresponds to a number:

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

The program must:

1. Return the numeric value of a resistor color.
2. Return a list of all available resistor colors.

---

# 2. Your Program

## Header File (resistor_color.h)

```c
#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

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

int color_code(resistor_band_t color);
const resistor_band_t *colors(void);

#endif
```

---

## Source File (resistor_color.c)

```c
#include "resistor_color.h"

int color_code(resistor_band_t color)
{
    return color;
}

const resistor_band_t *colors(void)
{
    static const resistor_band_t bands[] = {
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
    };

    return bands;
}
```

---

# 3. Improved Version

The above solution is already good for the exercise.

A slightly more maintainable version:

```c
#include "resistor_color.h"

static const resistor_band_t BANDS[] = {
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
};

int color_code(resistor_band_t color)
{
    return color;
}

const resistor_band_t *colors(void)
{
    return BANDS;
}
```

### Improvement

Moves the array outside the function.

Benefits:

* Created only once.
* Easier to find and modify.
* Cleaner function.

---

# 4. Example Inputs and Outputs

## Example 1

```c
color_code(BLACK);
```

Output:

```text
0
```

---

## Example 2

```c
color_code(RED);
```

Output:

```text
2
```

---

## Example 3

```c
color_code(GREEN);
```

Output:

```text
5
```

---

## Example 4

```c
color_code(WHITE);
```

Output:

```text
9
```

---

## Example 5

```c
const resistor_band_t *bands = colors();
```

Contents of the returned array:

```text
BLACK
BROWN
RED
ORANGE
YELLOW
GREEN
BLUE
VIOLET
GREY
WHITE
```

---

# 5. Things Learned

---

# Header Files

File:

```c
resistor_color.h
```

Contains:

```c
typedef enum ...
```

and function declarations.

Purpose:

```text
Tell other files what exists.
```

Think of it as a contract.

Example:

```c
int add(int a, int b);
```

means:

```text
A function named add exists.
It accepts two integers.
It returns an integer.
```

The actual code lives elsewhere.

---

# Source Files

File:

```c
resistor_color.c
```

Contains actual implementations.

Example:

```c
int add(int a, int b)
{
    return a + b;
}
```

Rule:

```text
.h = declarations
.c = implementations
```

---

# typedef

Without typedef:

```c
enum color {
    RED,
    BLUE
};
```

Usage:

```c
enum color value;
```

With typedef:

```c
typedef enum {
    RED,
    BLUE
} color_t;
```

Usage:

```c
color_t value;
```

Much shorter and cleaner.

---

# enum

This is the most important concept in this exercise.

You wrote:

```c
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
```

The compiler automatically converts this into:

```c
typedef enum {
    BLACK = 0,
    BROWN = 1,
    RED = 2,
    ORANGE = 3,
    YELLOW = 4,
    GREEN = 5,
    BLUE = 6,
    VIOLET = 7,
    GREY = 8,
    WHITE = 9
} resistor_band_t;
```

---

# Why enum Exists

Without enum:

```c
int color = 2;
```

What does 2 mean?

Nobody knows.

---

With enum:

```c
resistor_band_t color = RED;
```

Immediately understandable.

---

# How color_code Works

Function:

```c
int color_code(resistor_band_t color)
{
    return color;
}
```

Looks strange.

Example:

```c
color_code(RED);
```

Compiler sees:

```c
color_code(2);
```

Returns:

```text
2
```

---

Example:

```c
color_code(GREEN);
```

Compiler sees:

```c
color_code(5);
```

Returns:

```text
5
```

---

# Arrays

This is your first real array in C.

```c
static const resistor_band_t bands[] = {
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
};
```

Memory representation:

```text
Index   Value

0       BLACK
1       BROWN
2       RED
3       ORANGE
4       YELLOW
5       GREEN
6       BLUE
7       VIOLET
8       GREY
9       WHITE
```

---

Accessing elements:

```c
bands[0]
```

Result:

```text
BLACK
```

---

```c
bands[2]
```

Result:

```text
RED
```

---

```c
bands[5]
```

Result:

```text
GREEN
```

---

# Pointers

This line introduces pointers:

```c
const resistor_band_t *colors(void);
```

Read it right-to-left:

```text
colors
is a function
that returns
a pointer
to resistor_band_t
```

---

Think of an array:

```c
bands
```

as:

```text
[BLACK][BROWN][RED][ORANGE]...
```

The pointer points to the first element:

```text
 ↓
[BLACK][BROWN][RED][ORANGE]...
```

Returning a pointer allows the caller to access the entire array.

---

# Why Not Return The Whole Array?

C does not allow:

```c
resistor_band_t[] colors(void);
```

Functions cannot directly return arrays.

Instead:

```c
return pointer to first element
```

---

# Understanding static

This is the hardest concept in the exercise.

Consider:

```c
const resistor_band_t *colors(void)
{
    resistor_band_t bands[] = {
        BLACK,
        BROWN
    };

    return bands;
}
```

Looks fine.

Actually broken.

---

Why?

When the function ends:

```text
bands is destroyed
```

The returned pointer now points to invalid memory.

This is called:

```text
Dangling Pointer
```

One of the most dangerous bugs in C.

---

Using:

```c
static const resistor_band_t bands[]
```

changes the lifetime.

Now:

```text
bands exists for entire program execution
```

Safe to return.

---

# const

You used:

```c
const resistor_band_t *colors(void)
```

Meaning:

```text
The caller may read the array.
The caller may not modify the array.
```

Good practice.

---

# Memory Visualization

Inside the program:

```text
bands

Index
0 → BLACK
1 → BROWN
2 → RED
3 → ORANGE
4 → YELLOW
5 → GREEN
6 → BLUE
7 → VIOLET
8 → GREY
9 → WHITE
```

Returned pointer:

```text
       ↓
[0][1][2][3][4][5][6][7][8][9]
```

The caller can walk through the array using indexes.

---

# 6. What Still Needs Improvement

## 1. Arrays

This is likely your first serious array exercise.

Practice:

* Creating arrays
* Accessing indexes
* Looping through arrays

---

## 2. Pointers

You are now using pointers indirectly.

Need deeper understanding of:

```c
*
&
```

operators.

---

## 3. Memory Lifetime

You have now encountered:

```c
static
```

for the first time.

Future topics:

* Stack memory
* Static memory
* Heap memory

---

## 4. Reading Complex Declarations

Example:

```c
const resistor_band_t *colors(void);
```

At first glance this looks scary.

You should practice reading declarations from right to left.

---

# 7. Mentor Notes

## What You Did Well

* Correct use of `enum`.
* Correct use of `typedef`.
* Correct use of header/source separation.
* Correct use of `static`.
* Returned a pointer safely.

---

## Common Beginner Mistakes

### Mistake 1

Returning a local array:

```c
resistor_band_t bands[];
return bands;
```

Dangerous.

---

### Mistake 2

Using many `if` statements:

```c
if(color == RED)
```

Not needed.

Enum already stores the value.

---

### Mistake 3

Not understanding that:

```c
RED
```

is actually:

```text
2
```

at runtime.

---

# Biggest Lesson From This Program

The resistor story is just a disguise.

The real lessons are:

```text
typedef
enum
arrays
pointers
static
header/source separation
```

This is your first exercise that introduces multiple core C concepts simultaneously. Understanding why `static` is needed and why `colors()` returns a pointer is far more valuable than memorizing resistor color codes.
