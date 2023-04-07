//CLASSIC SNAKE GAME

//BY:
//GROUP #18
//Davis O'connell
//Ali Mardini
//Jainish Prajapati
//Allison Venables

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "allmod.h"

//global variables
int gameover, score, highscore;
int x, y, fruitx, fruity, flag;

//function to set up the game
void setup()
{
    int  height = 20, width = 20;
    gameover = 0;

    x = height / 2;     //set initial snake position
    y = width / 2;
label1:         //set initial fruit position, ensuring it doesn't overlap with the snake
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1;
label2:
    fruity = rand() % 20;
    if (fruity == 0)
        goto label2;
    score = 0;
}

//main function
int main(void)
{
    char choice;

    setup();        //initial setup

    while (!gameover)       //play the game until the game is over
    {
        draw();         //draw the game board

        input();        //take input from the user

        logic();        //perform game logic
    }

    recordHighScore();          //record the high score

    printf("Do you want to play again? (y/n)");         //ask user if they want to play again
    scanf_s(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        main();     //restart the game
    }
    else
    {
        printf("Thanks for playing!");          //farewell message
        return 0;
    }
}