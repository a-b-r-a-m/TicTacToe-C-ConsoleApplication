#pragma once

typedef struct Player {
	char name[33];
	int w, d, l;
}player;

int GameOverWithPlayers(char grid[], player * P1, player * P2) {
	if ((grid[25] == 'X' && grid[29] == 'X' && grid[33] == 'X') || (grid[79] == 'X' && grid[83] == 'X' && grid[87] == 'X')
		|| (grid[133] == 'X' && grid[137] == 'X' && grid[141] == 'X') || (grid[25] == 'X' && grid[79] == 'X' && grid[133] == 'X')
		|| (grid[29] == 'X' && grid[83] == 'X' && grid[137] == 'X') || (grid[33] == 'X' && grid[87] == 'X' && grid[141] == 'X')
		|| (grid[25] == 'X' && grid[83] == 'X' && grid[141] == 'X') || (grid[33] == 'X' && grid[83] == 'X' && grid[133] == 'X'))
	{
		printf("\n%s won.\n", P1->name);
		++(P1->w);
		++(P2->l);
		return 1;
	}

	if ((grid[25] == 'O' && grid[29] == 'O' && grid[33] == 'O') || (grid[79] == 'O' && grid[83] == 'O' && grid[87] == 'O')
		|| (grid[133] == 'O' && grid[137] == 'O' && grid[141] == 'O') || (grid[25] == 'O' && grid[79] == 'O' && grid[133] == 'O')
		|| (grid[29] == 'O' && grid[83] == 'O' && grid[137] == 'O') || (grid[33] == 'O' && grid[87] == 'O' && grid[141] == 'O')
		|| (grid[25] == 'O' && grid[83] == 'O' && grid[141] == 'O') || (grid[33] == 'O' && grid[83] == 'O' && grid[133] == 'O'))
	{
		printf("\n%s won.\n", P2->name);
		++(P2->w);
		++(P1->l);
		return 1;
	}

	return 0;
}

void PlayWithPlayers(char grid[], player * P1, player * P2) {
	char choice = '?';
	int i, cnt = 1;
	while (choice != '0') {
		for (i = 1; i < 10; ++i) {
			printf("\nPick a cell %s: ", ((i + cnt - 1) & 1) ? P1->name : P2->name);
			scanf(" %c", &choice);
			while (!isdigit(choice) || choice == '0' || IsTaken(grid, choice)) {
				printf("\nInvalid choice. Choose free cell from 1-9: ");
				scanf_s(" %c", &choice);
			}
			if (i & 1 == 1)
				UpdateGrid(grid, choice, 'X');
			else
				UpdateGrid(grid, choice, 'O');
			printf("\n\n");
			printf(grid);
			if (cnt & 1 == 1) {
				if (GameOverWithPlayers(grid, P1, P2))
					break;
			}
			else
				if (GameOverWithPlayers(grid, P2, P1))
					break;
		}
		if (i == 10) {
			printf("\nIt's a draw.\n");
			++(P1->d);
			++(P2->d);
		}
		printf("\nTo play new game enter any key; enter \"0\" to exit: ");
		scanf(" %c", &choice);
		RestartGrid(grid);
		++cnt;
	}
}

void MakePlayer(player ** tmpptr) {
	char confirm = '?';
	char pName[33];
	while (confirm != 'y') {
		printf("Enter desired name: ");
		scanf("%s", pName);
		printf("You chose \"%s\" as your name.\n\nEnter \n\"y\" to confirm\nany other key otherwise\n\n: ", pName);
		scanf(" %c", &confirm);
	}
	*tmpptr = (player *)malloc(sizeof(player));
	memcpy((*tmpptr)->name, pName, strlen(pName) + 1);
	(*tmpptr)->w = 0;
	(*tmpptr)->d = 0;
	(*tmpptr)->l = 0;
}

void UpdatePlayerStats(player * tmpptr, char line[256], int correctChars) { //needs improvement; after 99 resets to 10
	int cCreset, i, j, digitCnt = 0, numOfDs = 0;
	double strToNum = 0;
	char letter;
	for (i = 0; i < 3; ++i) {
		correctChars += 4;
		cCreset = correctChars;
		letter = line[correctChars];
		digitCnt = 0;
		while (isdigit(letter)) {
			letter = line[++correctChars];
			++digitCnt;
		}
		for (j = 0; j < digitCnt; ++j) {
			strToNum += ((line[--correctChars] * pow(10.0, j)) - 48);
		}
		if (i == 0)
			strToNum += tmpptr->w;
		else if (i == 1)
			strToNum += tmpptr->d;
		else
			strToNum += tmpptr->l;
		numOfDs = log10((int)strToNum) + 1;
		correctChars += (digitCnt - 1);
		for (j = 0; j < numOfDs; ++j) {
			line[correctChars--] = ((int)strToNum % 10) + 48;
			strToNum = (int)strToNum / 10;
		}
		correctChars = cCreset;
	}
}

int CompareNames(player * tmpptr, char line[256], int * correctChars) {
	int i, nameLength;
	nameLength = strlen(tmpptr->name);
	int identical = 0;
	for (i = 0; i < nameLength; ++i)
		if (line[i] != (tmpptr->name)[i])
			break;
		else
			++(*correctChars);

	if (*correctChars == nameLength)
		return 1;

	return 0;
}