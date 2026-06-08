# Queen Attack

---

# 1. Problem Statement

Given the positions of two queens on a chessboard, determine whether they can attack each other.

In chess, a queen can attack another piece if they are:

* On the same row
* On the same column
* On the same diagonal

The chessboard is an 8×8 board with coordinates ranging from:

```text
Rows:    0 to 7
Columns: 0 to 7
```

If either queen is placed outside the board, or both queens occupy the same square, the position is considered invalid.

---

## Example

White Queen:

```text
(row=2, column=3)
```

Black Queen:

```text
(row=5, column=6)
```

Differences:

```text
|5 - 2| = 3
|6 - 3| = 3
```

Since the row difference equals the column difference, the queens share a diagonal.

Result:

```text
CAN_ATTACK
```

---

# 2. Your Program

```c
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
    CAN_NOT_ATTACK,
    CAN_ATTACK,
    INVALID_POSITION
} attack_status_t;

typedef struct {
    uint8_t row;
    uint8_t column;
} position_t;

int is_invalid_position(position_t queen_1, position_t queen_2);
attack_status_t can_attack(position_t queen_1, position_t queen_2);

int main(void) {
    position_t queen_1;
    position_t queen_2;

    queen_1.column = 3;
    queen_1.row = 2;
    queen_2.column = 6;
    queen_2.row = 5;

    switch (can_attack(queen_1, queen_2)) {
        case CAN_ATTACK :
            printf("Can attack");
            break;
        case CAN_NOT_ATTACK :
            printf("Cannot attack");
            break;
        case INVALID_POSITION :
            printf("Invalid position");
            break;
        default :
            printf("Error");
    }
}

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if(is_invalid_position(queen_1, queen_2)) {
        return INVALID_POSITION;
    }

    if(
        (queen_1.row == queen_2.row) ||
        (queen_1.column == queen_2.column) ||
        (abs(queen_1.column - queen_2.column) == abs(queen_1.row - queen_2.row))
    ) {
        return CAN_ATTACK;
    } else {
        return CAN_NOT_ATTACK;
    }
}

int is_invalid_position(position_t queen_1, position_t queen_2) {
    return (
        (queen_1.column >= 8 || queen_1.row >= 8) ||
        (queen_2.column >= 8 || queen_2.row >= 8) ||
        (queen_1.column == queen_2.column &&
         queen_1.row == queen_2.row)
    );
}
```

---

# 3. Improved Version

The logic is already correct. The main improvements are readability and using boolean return values.

```c
#include <stdbool.h>

bool is_invalid_position(position_t queen_1, position_t queen_2);

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (is_invalid_position(queen_1, queen_2)) {
        return INVALID_POSITION;
    }

    if (
        queen_1.row == queen_2.row ||
        queen_1.column == queen_2.column ||
        abs(queen_1.row - queen_2.row) ==
        abs(queen_1.column - queen_2.column)
    ) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}
```

---

# 4. Example Inputs and Outputs

---

## Example 1: Same Row

```text
White: (2,3)
Black: (2,6)
```

Board:

```text
. . . W . . B .
```

Result:

```text
CAN_ATTACK
```

---

## Example 2: Same Column

```text
White: (1,5)
Black: (6,5)
```

Board:

```text
      W
      .
      .
      .
      .
      .
      B
```

Result:

```text
CAN_ATTACK
```

---

## Example 3: Same Diagonal

```text
White: (2,2)
Black: (5,5)
```

Differences:

```text
|5 - 2| = 3
|5 - 2| = 3
```

Result:

```text
CAN_ATTACK
```

---

## Example 4: Cannot Attack

```text
White: (2,4)
Black: (6,6)
```

Check:

```text
Same row?     No
Same column?  No

|6-2| = 4
|6-4| = 2
```

Result:

```text
CAN_NOT_ATTACK
```

---

## Example 5: Same Position

```text
White: (3,4)
Black: (3,4)
```

Result:

```text
INVALID_POSITION
```

---

## Example 6: Outside Board

```text
White: (8,2)
Black: (0,0)
```

Result:

```text
INVALID_POSITION
```

---

# 5. Things Learned

---

# Structures (`struct`)

This is likely your first exercise using structures.

A structure groups related data together.

Example:

```c
typedef struct {
    uint8_t row;
    uint8_t column;
} position_t;
```

Instead of:

```c
int row;
int column;
```

everywhere, we can create:

```c
position_t queen;
```

and access:

```c
queen.row
queen.column
```

---

# Enumerations (`enum`)

Enums allow us to create named constants.

```c
typedef enum {
    CAN_NOT_ATTACK,
    CAN_ATTACK,
    INVALID_POSITION
} attack_status_t;
```

Compiler interpretation:

```text
CAN_NOT_ATTACK = 0
CAN_ATTACK = 1
INVALID_POSITION = 2
```

approximately.

Instead of returning:

```c
return 0;
```

we return:

```c
return CAN_ATTACK;
```

which is far easier to understand.

---

# Switch Statements

Instead of:

```c
if(status == CAN_ATTACK)
```

you used:

```c
switch(status)
{
    case CAN_ATTACK:
        ...
}
```

This is useful when handling several possible enum values.

---

# Unsigned Integer Types

You used:

```c
uint8_t
```

from:

```c
#include <stdint.h>
```

Meaning:

```text
Unsigned
8 bits
Range: 0 to 255
```

Perfect for chessboard coordinates.

---

# Absolute Value

Function:

```c
abs()
```

Header:

```c
#include <stdlib.h>
```

Example:

```c
abs(-5)
```

Result:

```text
5
```

Used for diagonal checking:

```c
abs(row1 - row2)
==
abs(column1 - column2)
```

---

# Diagonal Detection

This is the most important idea in the exercise.

Queens are on the same diagonal when:

```text
Absolute row difference
=
Absolute column difference
```

Example:

```text
(2,2)
(5,5)

|5-2| = 3
|5-2| = 3
```

Diagonal.

---

# Validation Functions

You separated validation into:

```c
is_invalid_position()
```

This is good design.

Responsibility:

```text
Check whether the board state is legal.
```

The attack function can then focus only on attack logic.

---

# Program Flow

```text
Receive two queen positions
            ↓
Validate positions
            ↓
Invalid?
    ↓            ↓
   Yes           No
    ↓            ↓
Return      Check row
INVALID         ↓
          Check column
                ↓
          Check diagonal
                ↓
     Attack?        No Attack?
        ↓               ↓
 CAN_ATTACK    CAN_NOT_ATTACK
```

---

# 6. What Still Needs Improvement

### 1. Boolean Return Types

Instead of:

```c
int is_invalid_position(...)
```

prefer:

```c
bool is_invalid_position(...)
```

because the function answers a true/false question.

---

### 2. Enum Ownership

When Exercism provides a header file:

```c
queen_attack.h
```

always use the enum definitions exactly as provided.

Changing enum order can break tests.

---

### 3. Understanding Integer Promotion

This expression:

```c
queen_1.column - queen_2.column
```

works because C promotes `uint8_t` values to `int` before subtraction.

This is an important language rule you'll encounter more often.

---

### 4. More Struct Practice

You now know:

```c
typedef struct
```

Next steps:

* Passing structs
* Returning structs
* Arrays of structs
* Struct pointers

---

# 7. Mentor Notes

This exercise is not really about chess.

The real lessons are:

```text
Structs
Enums
Coordinate systems
Validation
Absolute values
Problem decomposition
```

The queen is simply a story used to package those concepts.

---

## What You Did Well

✓ Correctly identified attack conditions.

✓ Correctly used diagonal mathematics.

✓ Created a dedicated validation function.

✓ Used enums instead of magic numbers.

✓ Used a struct to model a position.

✓ Used a switch statement appropriately.

---

## Common Mistakes You Avoided

### Mistake 1

Checking only one diagonal direction.

Wrong:

```c
row1 - row2 == column1 - column2
```

Your use of `abs()` correctly handles all four diagonal directions.

---

### Mistake 2

Trying to simulate queen movement square-by-square.

You reduced the problem to coordinate comparisons.

This is more efficient and more elegant.

---

### Mistake 3

Mixing validation with attack logic.

Separating validation into its own function made the code cleaner.

---

# Personal Mentor Assessment

```text
Functions          : Beginner+
Loops              : Strong Beginner
Integer Types      : Beginner+
Enums              : Beginner+
Structs            : Beginner+
Problem Solving    : Intermediate Beginner
Arrays             : Beginner
Pointers           : Not Demonstrated
Strings            : Not Demonstrated
Dynamic Memory     : Not Demonstrated
Memory Lifetime    : Beginner
```

### Key Achievement

This is your first exercise where you successfully combined:

```text
Structs
Enums
Functions
Validation
Geometry
```

into a single solution.

That's a meaningful step beyond simple arithmetic and loop exercises. The next major milestone is learning arrays and pointers, because they will unlock much more of the C language.
