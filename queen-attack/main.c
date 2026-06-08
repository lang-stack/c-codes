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
        (queen_1.column >= 8 || queen_1.row >= 8) || (queen_2.column >= 8 || queen_2.row >= 8) ||
        (queen_1.column == queen_2.column && queen_1.row == queen_2.row)
    );
}