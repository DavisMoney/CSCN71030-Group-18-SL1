#include "collision.h"

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20
#define SNAKE_MAX_LENGTH 100

int board[BOARD_WIDTH][BOARD_HEIGHT];
int snake[SNAKE_MAX_LENGTH][2];
int snake_length = 3;
int score = 0;


void initialize_board()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            board[i][j] = 0;
        }
    }
}

void initialize_snake()
{
    snake[0][0] = BOARD_WIDTH / 2;
    snake[0][1] = BOARD_HEIGHT / 2;
    snake[1][0] = snake[0][0] - 1;
    snake[1][1] = snake[0][1];
    snake[2][0] = snake[1][0] - 1;
    snake[2][1] = snake[1][1];
    for (int i = 0; i < snake_length; i++)
    {
        board[snake[i][0]][snake[i][1]] = 1;
    }
}

void generate_food()
{
    int x, y;
    do
    {
        x = rand() % BOARD_WIDTH;
        y = rand() % BOARD_HEIGHT;
    } while (board[x][y] != 0);
    board[x][y] = -1;
}

void move_snake(int dx, int dy)
{
    int tail[2];
    tail[0] = snake[snake_length - 1][0];
    tail[1] = snake[snake_length - 1][1];
    for (int i = snake_length - 1; i > 0; i--)
    {
        snake[i][0] = snake[i - 1][0];
        snake[i][1] = snake[i - 1][1];
    }
    snake[0][0] += dx;
    snake[0][1] += dy;
    if (board[snake[0][0]][snake[0][1]] == -1) {
        snake_length++;
        score++;
        generate_food();
    }
    else if (board[snake[0][0]][snake[0][1]] == 1) {
        printf("Game Over\n");
        exit(0);
    }
    board[tail[0]][tail[1]] = 0;
    board[snake[0][0]][snake[0][1]] = 1;
}