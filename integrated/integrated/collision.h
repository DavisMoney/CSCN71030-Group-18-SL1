#ifndef COLLISION_H
#define COLLISION_H

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20
#define SNAKE_MAX_LENGTH 100

extern int board[BOARD_WIDTH][BOARD_HEIGHT];
extern int snake[SNAKE_MAX_LENGTH][2];
extern int snake_length;
extern int score;

void initialize_board();
void initialize_snake();
void generate_food();
void move_snake(int dx, int dy);

#endif /* COLLISION_H */
