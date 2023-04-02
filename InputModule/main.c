#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "input.h"

//function to handle user input
void handle_input()
{
    //check if a key has been pressed
    if (_kbhit())
    {
        //get the pressed key
        char key = _getch();

        //check which key has been pressed
        switch (key)
        {
            //move snake up
        case 'w':
        case 'W':
            set_direction(UP);
            break;

            //move snake down
        case 's':
        case 'S':
            set_direction(DOWN);
            break;

            //move snake left
        case 'a':
        case 'A':
            set_direction(LEFT);
            break;

            //move snake right
        case 'd':
        case 'D':
            set_direction(RIGHT);
            break;

            //quit the game
        case 'q':
        case 'Q':
            set_game_over(true);
            break;
        }
    }
}


int main(void)
{
    //initialize the game
    initialize_game();

    //game loop
    while (is_game_over() == false)
    {
        //handle user input
        handle_input();

        //update the snake's behavior and movement
        update_snake();

        //check for collisions
        check_collisions();

        //display the game
        display_game();
    }

    //game over
    display_highscore();
    return 0;
}