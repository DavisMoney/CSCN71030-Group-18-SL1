#include <stdbool.h>
#include "input.h"

//global variables
int direction;
bool game_over;

void initialize_game()
{
    //initialize the snake's direction and game over status
    direction = RIGHT;
    game_over = false;
}

void set_direction(int new_direction)
{
    //update the snake's direction
    direction = new_direction;
}

void set_game_over(bool new_game_over)
{
    //update the game over status
    game_over = new_game_over;
}

bool is_game_over()
{
    //return the current game over status
    return game_over;
}

void update_snake()
{
    //update the snake's behavior and movement based on the current direction

}

void check_collisions()
{
    //check for collisions with the walls and other objects in the game

}

void display_game()
{
    //display the game on the screen

}

void display_highscore()
{
    //display the high score at the end of the game

}