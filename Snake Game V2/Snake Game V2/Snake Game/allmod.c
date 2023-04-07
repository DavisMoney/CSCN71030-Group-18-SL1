#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "allmod.h"

//initializing global variables
int gameover, score, highscore;
int x, y, fruitx, fruity, flag;
int i, j;
int height = 20, width = 20;

//function to draw the game board
void draw()
{
    system("cls");          //clearing the console screen
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1
                || j == 0 || j == width - 1)
            {
                printf("#");       //drawing the borders of the game board
            }
            else {
                if (i == x && j == y)
                    printf("0");        //drawing the snake's head
                else if (i == fruitx && j == fruity)
                    printf("*");        //drawing the fruit
                else
                    printf(" ");        //drawing the empty spaces
            }
        }
        printf("\n");
    }
    printf("score = %d", score);        //displaying the player's score
    printf("\n");
    printf("high score = %d", highscore);       //displaying the high score
    printf("\n");
    printf("press X to quit the game");     //prompting the user to quit the game
}

//function to get user input
void input()
{
    if (_kbhit())       //checking if a key has been pressed
    {
        switch (getch())
        {
        case 'a':
            flag = 1;       //moving left
            break;
        case 's':
            flag = 2;       //moving down
            break;
        case 'd':
            flag = 3;       //moving right
            break;
        case 'w':
            flag = 4;       //moving up
            break;
        case 'x':
            gameover = 1;       //ending the game
            break;
        }
    }
}

//function to control the game logic
void logic()
{
    Sleep(100);         //wait for some time before updating the snake's position
    switch (flag)
    {
    case 1:         //if 'a' is pressed, move the snake to the left by decreasing the y-coordinate
        y--;
        break;
    case 2:         //if 's' is pressed, move the snake down by increasing the x-coordinate
        x++;
        break;
    case 3:         //if 'd' is pressed, move the snake to the right by increasing the y-coordinate
        y++;
        break;
    case 4:         // If 'w' is pressed, move the snake up by decreasing the x-coordinate
        x--;
        break;
    default:
        break;
    }

    if (x < 0 || x >= height || y < 0 || y >= width)        //check if the snake has hit the boundary
        gameover = 1;

    if (x == fruitx && y == fruity)         //check if the snake has eaten the fruit
    {
        fruitx = rand() % (height - 2) + 1;         //after eating the fruit generate new fruit at random position
        fruity = rand() % (width - 2) + 1;

        score += 1;         //increment score
    }
}

//function to record the high score in a file
void recordHighScore()
{
    FILE* fp;
    errno_t err = fopen_s(&fp, "highscore.txt", "r");        //open file in read mode
    if (err != 0)
    {
        printf("Error opening file!");           //if file opening failed
        return;
    }

    fscanf_s(fp, "%d", &highscore);         //read the high score from the file
    fclose(fp);         //close the file

    if (score > highscore)
    {
        err = fopen_s(&fp, "highscore.txt", "w");       //open file in write mode
        if (err != 0)
        {
            printf("Error opening file!");          //if file opening failed
            return;
        }
        fprintf(fp, "%d", score);           //write the new high score to the file
        fclose(fp);         //close the file

        printf("New high score recorded: %d\n", score);         //display the new high score
    }
    else
    {
        printf("Your score: %d\n", score);          //display the current score
        printf("High score: %d\n", highscore);      //display the high score
    }
}