#include "input.h"
#include <conio.h>

direction get_input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 75: return LEFT;
        case 77: return RIGHT;
        case 72: return UP;
        case 80: return DOWN;
        default: return NONE;
        }
    }
    return NONE;
}