#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "movement.h"
#include "collision.h"
#include "highscore.h"

#define SCORE_FILE "scores.txt"

int main()
{
    int scoreList[SCORE_CUTOFF];
    int dx = 0, dy = 0;
    char input;
    srand(time(NULL));

    //initialize game board
    GameStartup();
    initialize_snake();
    generate_food();

    // load previous high scores
    LoadScoresFromFile(SCORE_FILE, scoreList);

    while (1)
    {
        // print game board
        PrintGame();

        // move snake
        Move(dx, dy);

        // check if snake hits walls or its tail
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
            printf("Game Over\n");
            CompareAllScores(score, scoreList);
            DisplayScores(scoreList, score);
            SaveScoresToFile(scoreList, SCORE_FILE);
            break;
        }
        for (int i = 0; i < len; i++) {
            if (tailX[i] == x && tailY[i] == y) {
                printf("Game Over\n");
                CompareAllScores(score, scoreList);
                DisplayScores(scoreList, score);
                SaveScoresToFile(scoreList, SCORE_FILE);
                break;
            }
        }

        // check for collision and update board
        if (check_collision() == 1)
        {
            printf("Game Over\n");
            CompareAllScores(score, scoreList);
            DisplayScores(scoreList, score);
            SaveScoresToFile(scoreList, SCORE_FILE);
            break;
        }

        // update food and score
        Food();

        // get input
        if (_kbhit()) {
            input = _getch();
            switch (input)
            {
            case 'w':
                dx = -1;
                dy = 0;
                break;
            case 's':
                dx = 1;
                dy = 0;
                break;
            case 'a':
                dx = 0;
                dy = -1;
                break;
            case 'd':
                dx = 0;
                dy = 1;
                break;
            case 'x':
                printf("Game Over\n");
                CompareAllScores(score, scoreList);
                DisplayScores(scoreList, score);
                SaveScoresToFile(scoreList, SCORE_FILE);
                break;
            default:
                break;
            }
        }

        // update game speed
        Sleep(100);
    }

    return 0;
}
