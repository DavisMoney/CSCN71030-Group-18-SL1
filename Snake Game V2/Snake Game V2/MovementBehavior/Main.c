/*******************************************************
Name:	Davis O'Connell
Date:	26-Mar-2023
Desc:	Main program that runs all the functions
********************************************************/

#include "Global.h"


int main(void) {
	GameStartup();
	while (1) {
		PrintGame();
		Move(input);
		Food();
		Sleep(SPEED);
	}


	return 0;
}