#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20
#define SNAKE_LEN 5
#define SPEED 75

int tailX[100], tailY[100];
int x, y, fx, fy, extraFx1, extraFy1, extraFx2, extraFy2, len, score;
int input;

// Function declarations
void GameStartup();
void PrintGame();
void Move(int input);
void Food();

#endif
