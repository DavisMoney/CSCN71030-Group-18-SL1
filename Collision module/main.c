#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "collision.h"
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20
#define SNAKE_MAX_LENGTH 100



int main() {
    srand((unsigned int)time(NULL));
    initialize_board();
    initialize_snake();
    generate_food();
    while (true) {
        // code for moving the snake
        // get user input for the direction of movement
        // call move_snake(dx, dy)
        // code for displaying the game board and score
    }
    return 0;
}