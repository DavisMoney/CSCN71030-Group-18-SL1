/***********************************************
Name:	Max v
Date:	23-Mar-2023
Desc:	main source file for demonstrating
		high score module elements. This
		file isn't needed for the final
		snake game, only the other .c and
		the .h
***********************************************/

#include "highscore.h"

int main(void) {
	int playerScore;
	char* scoreFile = "highscores.txt";
	int highscores[SCORE_CUTOFF] = { 0 };

	//simulating receiving player score at end of game
	printf("Enter an integer score: ");
	scanf_s("%d", &playerScore);

	//retrival of highscores and placing new score in
	LoadScoresFromFile(scoreFile, highscores);
	CompareAllScores(playerScore, highscores);

	//updating highscore file
	SaveScoresToFile(highscores, scoreFile);

	//displaying scores and user's placement
	DisplayScores(highscores, playerScore);

	return 0;
}