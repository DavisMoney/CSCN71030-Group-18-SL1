//this directive ensures that the contents of this header file are only included once during compilation
#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

//these are header files that are included in this header file, providing access to the functions they contain
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//function prototypes for functions defined in the source code files
void setup();		//sets up the game board and initializes variables
void draw();		//draws the game board and snake on the console
void input();		//detects user input and changes the direction of the snake accordingly
void logic();		//updates the game state based on the user input and checks for collisions
void recordHighScore();		//saves the player's high score to a file

//this directive ends the header file inclusion prevention started with #ifndef
#endif //SNAKE_GAME_H