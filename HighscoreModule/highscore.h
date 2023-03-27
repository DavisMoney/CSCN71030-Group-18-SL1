#pragma once
/****************************************
Name:	Max Venables
Date:	23-Mar-2023
Desc:	Header file for the highscore
		module functions.
******************************************/

#include <stdio.h>

#define SCORE_CUTOFF	10

/********************************************************
Purpose:	save input integer array to specified text
			file.
Input:		scoreList	int[]	scores being saved
			scoreFile	char*	name of score file
Output:		void
*********************************************************/
void SaveScoresToFile(int scoreList[], char* scoreFile);

/********************************************************
Purpose:	loads all lines from a specified file into
			an array of integers.
Input:		scoreFile	char*	name of score file
			scoreList	int[]	array of scores (empty)
Output:		void
*********************************************************/
void LoadScoresFromFile(char* scoreFile, int scoreList[]);

/********************************************************
Purpose:	compares specified score to all other scores
			in an array
Input:		score		int		player's score
			scoreList	int[]	array of scores
Output:		void
*********************************************************/
void CompareAllScores(int score, int scoreList[]);

/**********************************************************
Purpose:	prints all integer values from an array to the
			screen in a formatted way.
Input:		scoreList	int[]	array of scores from file
			score		int		player's score
Output:		void
************************************************************/
void DisplayScores(int scoreList[], int score);