# Darts

## 1. Problem Statement

A dart is thrown at a dartboard centered at:

```text
(0, 0)
```

The dartboard contains three concentric circles:

| Circle        | Radius | Score |
| ------------- | ------ | ----- |
| Inner         | 1      | 10    |
| Middle        | 5      | 5     |
| Outer         | 10     | 1     |
| Outside Board | > 10   | 0     |

Given the coordinates where a dart lands:

```text
(x, y)
```

determine the score earned by the player.

---

## 2. Your Program

```c
#include <stdio.h>
#include <stdint.h>

typedef struct {
    float x;
    float y;
} coordinate_t;

float square(float point);
uint8_t score(coordinate_t landing_position);

int main(void) {
    coordinate_t landing_position = { 3.0F, 4.0F };
    printf("%d\n", score(landing_position));
}

uint8_t score(coordinate_t landing_position) {
    float distance = square(landing_position.x) + square(landing_position.y);

    if(distance <= 1.0F) {
        return 10;
    }

    if(distance <= 25.0F) {
        return 5;
    }

    if(distance <= 100.0F) {
        return 1;
    }

    return 0;
}

float square(float point) {
    return point * point;
}
```

---

## 3. Improved Version

The logic is already correct. The main improvement is naming the variable according to what it actually stores.

```c
#include <stdint.h>

typedef struct {
    float x;
    float y;
} coordinate_t;

static float square(float value)
{
    return value * value;
}

uint8_t score(coordinate_t landing_position)
{
    float distance_squared =
        square(landing_position.x) +
        square(landing_position.y);

    if (distance_squared <= 1.0F) {
        return 10;
    }

    if (distance_squared <= 25.0F) {
        return 5;
    }

    if (distance_squared <= 100.0F) {
        return 1;
    }

    return 0;
}
```

---

## 4. Example Inputs and Outputs

### Example 1

Input:

```text
(0, 0)
```

Calculation:

```text
0² + 0² = 0
```

Result:

```text
10
```

---

### Example 2

Input:

```text
(0.7, 0.7)
```

Calculation:

```text
0.7² + 0.7²
= 0.49 + 0.49
= 0.98
```

Result:

```text
10
```

---

### Example 3

Input:

```text
(3, 4)
```

Calculation:

```text
3² + 4²
= 9 + 16
= 25
```

Result:

```text
5
```

---

### Example 4

Input:

```text
(6, 0)
```

Calculation:

```text
6² + 0²
= 36
```

Result:

```text
1
```

---

### Example 5

Input:

```text
(11, 0)
```

Calculation:

```text
11² + 0²
= 121
```

Result:

```text
0
```

---

## 5. Things Learned

### Structures

You used a structure to represent a coordinate.

```c
typedef struct {
    float x;
    float y;
} coordinate_t;
```

This allows a point to be treated as a single object.

Example:

```c
coordinate_t point = { 3.0F, 4.0F };
```

Instead of:

```c
float x = 3.0F;
float y = 4.0F;
```

---

### Floating-Point Numbers

You worked with:

```c
float
```

and float literals:

```c
3.0F
0.7F
-5.0F
```

The `F` suffix tells the compiler:

```text
This is a float literal.
```

---

### Helper Functions

You created:

```c
float square(float point)
{
    return point * point;
}
```

This made the mathematical formula easier to read.

---

### Mathematical Modeling

The problem appears to be about darts, but the real problem is:

```text
Find distance from the center.
```

Once that distance is known, scoring becomes simple.

---

### Squared Distance Optimization

Normally distance is:

[
d = \sqrt{x^2 + y^2}
]

Your solution uses:

[
d^2 = x^2 + y^2
]

instead.

This avoids calling:

```c
sqrt()
```

while producing the same comparisons.

---

### Boundary Conditions

You correctly handled:

```text
Distance = 1
Distance = 5
Distance = 10
```

by using:

```c
<=
```

This ensures points on circle boundaries are included.

---

## 6. What Still Needs Improvement

### Variable Naming

Current:

```c
float distance;
```

Actual value:

```text
distance²
```

Better:

```c
float distance_squared;
```

The name should accurately describe the stored value.

---

### Static Helper Functions

The helper function:

```c
float square(float point)
```

is only used inside one file.

Later you can make it:

```c
static float square(float point)
```

to limit its visibility to that source file.

---

### More Floating-Point Practice

This is one of your first exercises involving:

```text
float
real numbers
distance calculations
```

More practice with floating-point arithmetic will be useful.

---

### More Struct Practice

Future topics:

```text
Arrays of structs
Pointers to structs
Returning structs
Nested structs
```

---

## 7. Mentor Notes

This exercise hides an important lesson.

Many beginners immediately think:

```text
I need the distance.
```

and write:

```c
sqrt(x*x + y*y)
```

You recognized that you only need to compare distances against fixed boundaries.

Therefore:

```text
Distance² is sufficient.
```

That simplification removes the need for square roots entirely.

---

### What You Did Well

✓ Correctly modeled the problem mathematically.

✓ Used a struct to represent a coordinate.

✓ Created a helper function for squaring values.

✓ Correctly handled all scoring boundaries.

✓ Avoided unnecessary use of `sqrt()`.

✓ Wrote clean and readable logic.

---

### Key Insight

The exercise is not really about darts.

The exercise is about:

```text
Coordinate systems
Distance calculations
Floating-point numbers
Mathematical simplification
```

The dartboard is simply a story used to package those concepts.

---

## Mentor Assessment

```text
Functions              : Beginner+
Loops                  : Strong Beginner
Integer Types          : Beginner+
Floating Point         : Beginner+
Enums                  : Beginner+
Structs                : Beginner+
Problem Solving        : Intermediate Beginner
Mathematical Modeling  : Intermediate Beginner
Arrays                 : Beginner
Pointers               : Not Demonstrated
Strings                : Not Demonstrated
Dynamic Memory         : Not Demonstrated
Memory Lifetime        : Beginner
```

### Key Achievement

This exercise demonstrates that you're beginning to translate a real-world description into a mathematical model first and then implement the model in code. That is a much more valuable skill than memorizing syntax.
