#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include "Mandatory.h"
#include "NoPlayers.h"
#include "Players.h"
#include"AI.h"

int main(void) {
	char grid[] = "         |   |   \n       1 | 2 | 3 \n      ___|___|___\n         |   |   \n       4 | 5 | 6 \n      ___|___|___\n         |   |   \n       7 | 8 | 9 \n         |   |   \n";
	char choice = '?', letter = '?';
	char playerName[33];
	int i, j, correctChars = 0, tmp1Old = 0, tmp2Old = 0;
	player *tmpptr1 = NULL, *tmpptr2 = NULL;
	FILE *StatsPtr = NULL, *tmpFile = NULL;
	char line[256];

MainMenu:
	printf("\n    TIC - TAC - TOE\n\n");
	printf(grid);
	printf("\n\n");
	printf("Enter \n\"1\" to play as guests\n\"2\"         as registered players\n\"3\"         against AI\n\n\"4\" for scores\n\n: ");
	scanf(" %c", &choice);
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
		printf("Invalid choice. Enter \n\"1\" to play as guests\n\"2\" to play as registered players\n\"3\" to play against AI\n\"4\" for scores\n\n: ");
		scanf(" %c", &choice);
	}
	if (choice == '2') {
		for (j = 1; j < 3; ++j) {
			printf("\nPLAYER %d:\n", j);
			if (j == 1)
				MakePlayer(&tmpptr1);
			else
				MakePlayer(&tmpptr2);
		}
		PlayWithPlayers(grid, tmpptr1, tmpptr2);
FileOps:
		StatsPtr = fopen("C:\\Users\\Pietahr\\Desktop\\PROJECTS\\AZ_AI\\PlayerStats.txt", "r");
		if (StatsPtr != NULL && tmpptr1 != NULL && tmpptr2 != NULL) {
			tmpFile = fopen("C:\\Users\\Pietahr\\Desktop\\PROJECTS\\AZ_AI\\TempPlayerStats.txt", "w+");
			while (fgets(line, sizeof line, StatsPtr) != NULL) {
				if (CompareNames(tmpptr1, line, &correctChars)) {
					tmp1Old = 1;
					UpdatePlayerStats(tmpptr1, line, correctChars);
				}
				correctChars = 0;
				if (CompareNames(tmpptr2, line, &correctChars)) {
					tmp2Old = 1;
					UpdatePlayerStats(tmpptr2, line, correctChars);
				}
				fprintf(tmpFile, "%s", line);
				correctChars = 0;
			}
		}
		if (StatsPtr != NULL)
			fclose(StatsPtr);
		if (tmpFile != NULL)
			fclose(tmpFile);

		tmpFile = fopen("C:\\Users\\Pietahr\\Desktop\\PROJECTS\\AZ_AI\\TempPlayerStats.txt", "a");
		if (tmpFile != NULL) {
			if (tmpptr1 != NULL && tmp1Old == 0)
				fprintf(tmpFile, "%s\t\tW:%d\tD:%d\tL:%d\n", tmpptr1->name, tmpptr1->w, tmpptr1->d, tmpptr1->l);
			if (tmpptr2 != NULL && tmp2Old == 0)
				fprintf(tmpFile, "%s\t\tW:%d\tD:%d\tL:%d\n", tmpptr2->name, tmpptr2->w, tmpptr2->d, tmpptr2->l);
			fclose(tmpFile);
		}

		if (tmpptr1 != NULL)
			free(tmpptr1);
		if (tmpptr2 != NULL)
			free(tmpptr2);

		remove("C:\\Users\\Pietahr\\Desktop\\PROJECTS\\AZ_AI\\PlayerStats.txt");
		StatsPtr = fopen("C:\\Users\\Pietahr\\Desktop\\PROJECTS\\AZ_AI\\PlayerStats.txt", "a");
		tmpFile = fopen("C:\\Users\\Pietahr\\Desktop\\PROJECTS\\AZ_AI\\TempPlayerStats.txt", "r");
		for (;;) {
			i = fgetc(tmpFile);
			letter = (char)i;
			if (i == EOF) {
				if (feof(tmpFile)) break;
				if (ferror(tmpFile)) break;
			}
			fputc(letter, StatsPtr);
		}
		if (StatsPtr != NULL)
			fclose(StatsPtr);
		if (tmpFile != NULL)
			fclose(tmpFile);
		remove("C:\\Users\\Pietahr\\Desktop\\PROJECTS\\AZ_AI\\TempPlayerStats.txt");
	}
	else if (choice == '1')
		Play(grid);
	else if (choice == '3') {
		printf("\nPLAYER:\n");
		MakePlayer(&tmpptr1);
		MakeAI(&tmpptr2);
		PlayAgaistAI(grid, tmpptr1, tmpptr2);
		goto FileOps;
	}
	else
		PrintStats();

	printf("\nEnter any key to go back to main menu, or enter \"0\" to exit game: ");
	scanf(" %c", &choice);

	if (choice != '0')
		goto MainMenu;
	printf("\nThank you for playing.\n\n");
	_sleep(1000);

	return 0;
}