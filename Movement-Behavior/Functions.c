/*******************************************************
Name:	Davis O'Connell
Date:	26-Mar-2023
Desc:	Hold what each function does from the code
********************************************************/

#include "Movement-Behavior.h"

void GameStartup() {
    //spawn point
    x = WIDTH / 2;
    y = HEIGHT / 2;
    //food spawn
    fx = rand() % WIDTH;
    fy = rand() % HEIGHT;
    extraFx1 = extraFy1 = extraFx2 = extraFy2 = -1;
    //snake length
    len = SNAKE_LEN;
    //starting score
    score = 0;
}

void PrintGame() {
    //clear board so it can reload
    system("cls");

    //top of board print
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    //prints side, snake, and food/extrafood
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");

            if (i == y && j == x)
                printf("O");

            else if (i == fy && j == fx)
                printf("F");

            else if (i == extraFy1 && j == extraFx1)
                printf("F");

            else if (i == extraFy2 && j == extraFx2)
                printf("F");

            else {
                int print = 0;
                for (int k = 0; k < len; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("=");
                        print = 1;
                    }
                }

                if (!print)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }
    //bottom of board
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
}

void Move(input) {
    //deals with moving
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < len; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    //direction choosen
    switch (input) {
    case 0:
        x++;
        break;
    case 1:
        y++;
        break;
    case 2:
        x--;
        break;
    case 3:
        y--;
        break;
    }
}

void Food() {

    if (x == fx && y == fy) {
        score += 10;
        //respawn food
        fx = rand() % WIDTH;
        fy = rand() % HEIGHT;
        len++;

        if (score % 50 == 0) {
            // spawn two extra every 50
            int extraFX1, extraFY1, extraFX2, extraFY2;
            do {
                extraFX1 = rand() % WIDTH;
                extraFY1 = rand() % HEIGHT;
                extraFX2 = rand() % WIDTH;
                extraFY2 = rand() % HEIGHT;
            } while ((extraFX1 == fx && extraFY1 == fy) || (extraFX2 == fx && extraFY2 == fy) || (extraFX1 == extraFX2 && extraFY1 == extraFY2));
            extraFx1 = extraFX1;
            extraFy1 = extraFY1;
            extraFx2 = extraFX2;
            extraFy2 = extraFY2;
        }
    }
    else if (x == extraFx1 && y == extraFy1) {
        score += 10;
        extraFx1 = -1;
        extraFy1 = -1;
        len++;
    }
    else if (x == extraFx2 && y == extraFy2) {
        score += 10;
        extraFx2 = -1;
        extraFy2 = -1;
        len++;
    }
}