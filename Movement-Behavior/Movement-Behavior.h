#pragma once

/*******************************************************
Name:	Davis O'Connell
Date:	26-Mar-2023
Desc:	States each int define include and function
********************************************************/


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

void GameStartup();

void PrintGame();

void Move(input);

void Food();














