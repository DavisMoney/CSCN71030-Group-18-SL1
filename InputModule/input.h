#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

//constants for the directions
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

//function prototypes
void initialize_game();
void set_direction(int direction);
void set_game_over(bool game_over);
bool is_game_over();
void update_snake();
void check_collisions();
void display_game();
void display_highscore();

#endif


//the "update_snake()", "check_collisions()", "display_game()", and "display_highscore()" functions are an example,
//they depend on the specific details of our teams other modules.