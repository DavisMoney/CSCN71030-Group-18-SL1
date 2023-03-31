#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#define SCORE_CUTOFF 10

#include <stdio.h>

// Saves the list of scores to a file.
void SaveScoresToFile(int scoreList[], char* scoreFile);

// Loads the list of scores from a file.
void LoadScoresFromFile(char* scoreFile, int scoreList[]);

// Compares the player's score to the list of high scores.
// If the player's score is higher than any of the high scores,
// their score is added to the list and the lowest score is removed.
void CompareAllScores(int score, int scoreList[]);

// Displays the list of high scores and the player's placement.
void DisplayScores(int scoreList[], int score);

#endif // HIGHSCORE_H
