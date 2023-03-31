#include "highscore.h"

void SaveScoresToFile(int scoreList[], char* scoreFile) {
	FILE* filePtr = NULL;

	fopen_s(&filePtr, scoreFile, "w");
	if (filePtr != NULL) {
		for (int i = 0; i < SCORE_CUTOFF; i++) {
			fprintf(filePtr, "%d\n", scoreList[i]);
		}
		fclose(filePtr);
	}
	else {
		printf("ERROR - file could not be accessed\n");
	}
}

void LoadScoresFromFile(char* scoreFile, int scoreList[]) {
	FILE* filePtr = NULL;
	int count = 0;

	fopen_s(&filePtr, scoreFile, "r");
	if (filePtr != NULL) {
		//read in all scores from file, if it exists
		while (fscanf_s(filePtr, "%d", &scoreList[count]) != EOF) {
			count++;
		}
		fclose(filePtr);
	}
	//if the file doesn't exist or there are less than ten scores
	for (count; count < SCORE_CUTOFF; count++) {
		scoreList[count] = 0;
	}
}

void CompareAllScores(int score, int scoreList[]) {
	int temp = 0;

	//reads through all scores in list 
	for (int i = 0; i < SCORE_CUTOFF; i++) {
		if (score > scoreList[i]) {
			//erases previously lowest score
			scoreList[SCORE_CUTOFF - 1] = 0;
			//moves all other scores down by one
			for (int j = SCORE_CUTOFF - 1; j >= i; j--) {
				scoreList[j] = scoreList[j - 1];
			}
			//sets player's current score in new placement
			scoreList[i] = score;
			temp = score;
			score = 0;
		}
	}
	if (score == 0) {
		score = temp;
	}
}

void DisplayScores(int scoreList[], int score) {
	int placement = 0;

	//prints all highscores in descending order
	for (int i = 0; i < SCORE_CUTOFF; i++) {
		printf("\t%d) %d POINTS\n", i + 1, scoreList[i]);
		if (scoreList[i] == score) {
			placement = i + 1;
		}
	}

	//determining where the user placed in the highscores
	if (placement == 0) {
		printf("You didn't place on the leaderboard this time.\n");
	}
	else if (placement == 1) {
		printf("You reached a new highest score!\n");
	}
	else if (placement == 2) {
		printf("You placed 2nd!\n");
	}
	else if (placement == 3) {
		printf("You placed 3rd!\n");
	}
	else {
		printf("You placed %dth!\n", placement);
	}
}