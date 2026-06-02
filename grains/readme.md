Since you're building personal notes, I'll make this version more complete and explain **`inttypes.h`**, **`PRIu64`**, and the reasoning behind them.

---

# Chessboard Grains

## 1. Problem Statement

A chessboard contains 64 squares.

The first square contains 1 grain of wheat.

Each subsequent square contains twice as many grains as the previous square.

```text
Square 1 = 1
Square 2 = 2
Square 3 = 4
Square 4 = 8
Square 5 = 16
...
```

Write functions to:

1. Calculate the number of grains on a given square.
2. Calculate the total number of grains on the entire chessboard.

Function signatures:

```c
uint64_t square(uint8_t index);
uint64_t total(void);
```

---

# 2. Your Program

```c
#include <stdio.h>
#include <stdint.h>

uint64_t square(uint8_t index);
uint64_t total(void);

int main() {
	printf("%llu\n", total());
	return 0;
}

uint64_t square(uint8_t index) {
	if(index == 0 || index > 64) {
		return 0;
	}

	return 1ULL << (index - 1);
}

uint64_t total() {
	const uint8_t total_squares = 64;
	uint64_t sum = 0;

	for(uint8_t i = 1; i <= total_squares; i++) {
		sum += square(i);
	}

	return sum;
}
```

---

# 3. Improved Version

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define CHESSBOARD_SQUARES 64

uint64_t square(uint8_t index);
uint64_t total(void);

int main(void) {
	printf("%" PRIu64 "\n", total());
	return 0;
}

uint64_t square(uint8_t index) {
	if(index < 1 || index > CHESSBOARD_SQUARES) {
		return 0;
	}

	return 1ULL << (index - 1);
}

uint64_t total(void) {
	uint64_t sum = 0;

	for(uint8_t i = 1; i <= CHESSBOARD_SQUARES; i++) {
		sum += square(i);
	}

	return sum;
}
```

---

# 4. Example Inputs and Outputs

## Example 1

```c
square(1);
```

Output:

```text
1
```

---

## Example 2

```c
square(2);
```

Output:

```text
2
```

---

## Example 3

```c
square(5);
```

Output:

```text
16
```

---

## Example 4

```c
square(10);
```

Output:

```text
512
```

---

## Example 5

```c
square(64);
```

Output:

```text
9223372036854775808
```

---

## Example 6

```c
total();
```

Output:

```text
18446744073709551615
```

---

# 5. Things Learned

---

## Fixed Width Integers (`stdint.h`)

Header:

```c
#include <stdint.h>
```

Provides integer types with guaranteed sizes.

Examples:

| Type     | Size    |
| -------- | ------- |
| uint8_t  | 8 bits  |
| uint16_t | 16 bits |
| uint32_t | 32 bits |
| uint64_t | 64 bits |

---

### Why Use These?

Normal C types are not guaranteed sizes.

Example:

```c
int value;
```

may be:

```text
2 bytes
4 bytes
8 bytes
```

depending on the machine.

But:

```c
uint64_t value;
```

always means:

```text
Unsigned 64-bit integer
```

This makes programs more portable.

---

## Understanding `uint8_t`

Used for:

```c
uint8_t index;
```

Represents:

```text
0 to 255
```

Which is enough for:

```text
1 to 64 squares
```

---

## Understanding `uint64_t`

Used for:

```c
uint64_t grains;
```

Represents:

```text
0 to 18,446,744,073,709,551,615
```

The chessboard problem requires very large numbers.

Using:

```c
unsigned int
```

would overflow.

---

## Bit Shifting (`<<`)

The operator:

```c
value << n
```

moves bits to the left.

Example:

```c
1 << 1
```

Binary:

```text
0001
0010
```

Result:

```text
2
```

---

Example:

```c
1 << 2
```

Binary:

```text
0001
0100
```

Result:

```text
4
```

---

Example:

```c
1 << 3
```

Binary:

```text
0001
1000
```

Result:

```text
8
```

---

## Why Does Left Shift Create Powers of Two?

Every left shift multiplies the value by 2.

```text
1 << 0 = 1
1 << 1 = 2
1 << 2 = 4
1 << 3 = 8
1 << 4 = 16
1 << 5 = 32
```

Which is:

```text
2^0
2^1
2^2
2^3
2^4
2^5
```

Therefore:

```text
1 << n
=
2^n
```

---

## Understanding `1ULL`

You asked:

> How are we calculating powers?

The answer is:

```c
1ULL << n
```

The shift creates powers of two.

But what is:

```c
1ULL
```

?

It means:

```text
Unsigned Long Long literal
```

Breaking it down:

```text
1     -> integer literal
U     -> unsigned
LL    -> long long
```

Therefore:

```c
1ULL
```

is a 64-bit unsigned integer with value:

```text
1
```

---

Without:

```c
1ULL
```

and using:

```c
1 << 63
```

the operation may overflow because `1` is usually an `int`.

Using:

```c
1ULL << 63
```

guarantees we have enough bits.

---

## Why `(index - 1)`?

Let's write the pattern:

```text
Square 1 = 1 = 2^0
Square 2 = 2 = 2^1
Square 3 = 4 = 2^2
Square 4 = 8 = 2^3
Square 5 = 16 = 2^4
```

Notice:

```text
Exponent = Square Number - 1
```

Therefore:

```c
1ULL << (index - 1)
```

produces:

```text
Square 1 -> 2^0
Square 2 -> 2^1
Square 3 -> 2^2
...
Square 64 -> 2^63
```

Exactly what the problem requires.

---

## Function Reuse

Instead of calculating powers twice:

```c
total()
```

reuses:

```c
square()
```

for every square.

Benefits:

* Less code
* Easier maintenance
* Easier debugging

---

## Input Validation

```c
if(index < 1 || index > 64)
```

Rejects invalid squares.

Examples:

```c
square(0);
square(65);
```

Both are invalid.

---

# Understanding `inttypes.h`

Header:

```c
#include <inttypes.h>
```

Works together with:

```c
#include <stdint.h>
```

---

## Why Does It Exist?

Suppose we have:

```c
uint64_t value = 100;
```

How do we print it?

You might write:

```c
printf("%llu", value);
```

Usually works.

But the C standard does not guarantee that:

```c
uint64_t
```

is always:

```c
unsigned long long
```

on every machine.

---

## Portable Solution

`inttypes.h` provides macros.

Example:

```c
PRIu64
```

means:

```text
Correct printf format for uint64_t
```

Usage:

```c
printf("%" PRIu64 "\n", value);
```

The compiler expands it into the correct format string.

---

## Understanding `PRIu64`

Break it down:

```text
PRI
```

Means:

```text
Print
```

---

```text
u
```

Means:

```text
Unsigned Integer
```

---

```text
64
```

Means:

```text
64-bit
```

---

Therefore:

```text
PRIu64
```

means:

```text
Print Format Specifier For Unsigned 64-bit Integer
```

---

Example:

```c
uint64_t grains = total();

printf("%" PRIu64 "\n", grains);
```

Portable on all platforms.

---

# 6. What Still Needs Improvement

## 1. Mathematical Formula

Current solution:

```text
Loop through all 64 squares.
```

Advanced solution:

```text
2^64 - 1
```

The total is a geometric series.

---

## 2. Learn More Bitwise Operators

You have now seen:

```c
<<
```

Next learn:

```c
>>
&
|
^
~
```

These are fundamental C operators.

---

## 3. Integer Overflow

Future topics:

* Overflow
* Underflow
* Integer promotion
* Type conversion

These become very important in C.

---

# 7. Mentor Notes

## What You Did Well

* Correct solution.
* Appropriate data types.
* Proper function decomposition.
* Good validation.
* Learned a low-level C technique (bit shifting).

---

## What I Didn't Like

* Function definition should match declaration:

```c
uint64_t total(void)
```

* Repeated magic number:

```c
64
```

* Relied on `%llu` instead of learning `PRIu64`.

---

## Biggest Lesson From This Program

This exercise is not really about chess.

It's about understanding that:

```c
1ULL << n
```

is a direct representation of:

```text
2^n
```

and that computers store numbers as bits, not as abstract mathematical objects.

This is your first real step into **thinking like the machine**, which is one of the most important skills in C programming.

---

## Personal Mentor Assessment

Current progression:

```text
Functions          : Strong Beginner
Loops              : Strong Beginner
Integer Types      : Strong Beginner
Bitwise Thinking   : Beginner
Problem Solving    : Beginner+
Arrays             : Not Demonstrated
Strings            : Not Demonstrated
Pointers           : Not Demonstrated
Structs            : Not Demonstrated
Dynamic Memory     : Not Demonstrated
```

This is your strongest exercise so far because it forced you to learn not just syntax, but how numbers are actually represented and manipulated at the binary level.
