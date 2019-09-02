#pragma once

int GameOver(char grid[]) {
	if (grid[25] == 'X' && grid[29] == 'X' && grid[33] == 'X') {
		printf("\nPlayer 1 won.\n");
		return 1;
	}
	if (grid[79] == 'X' && grid[83] == 'X' && grid[87] == 'X') {
		printf("\nPlayer 1 won.\n");
		return 1;
	}
	if (grid[133] == 'X' && grid[137] == 'X' && grid[141] == 'X') {
		printf("\nPlayer 1 won.\n");
		return 1;
	}
	if (grid[25] == 'X' && grid[79] == 'X' && grid[133] == 'X') {
		printf("\nPlayer 1 won.\n");
		return 1;
	}
	if (grid[29] == 'X' && grid[83] == 'X' && grid[137] == 'X') {
		printf("\nPlayer 1 won.\n");
		return 1;
	}
	if (grid[33] == 'X' && grid[87] == 'X' && grid[141] == 'X') {
		printf("\nPlayer 1 won.\n");
		return 1;
	}
	if (grid[25] == 'X' && grid[83] == 'X' && grid[141] == 'X') {
		printf("\nPlayer 1 won.\n");
		return 1;
	}
	if (grid[33] == 'X' && grid[83] == 'X' && grid[133] == 'X') {
		printf("\nPlayer 1 won.\n");
		return 1;
	}


	if (grid[25] == 'O' && grid[29] == 'O' && grid[33] == 'O') {
		printf("\nPlayer 2 won.\n");
		return 1;
	}
	if (grid[79] == 'O' && grid[83] == 'O' && grid[87] == 'O') {
		printf("\nPlayer 2 won.\n");
		return 1;
	}
	if (grid[133] == 'O' && grid[137] == 'O' && grid[141] == 'O') {
		printf("\nPlayer 2 won.\n");
		return 1;
	}
	if (grid[25] == 'O' && grid[79] == 'O' && grid[133] == 'O') {
		printf("\nPlayer 2 won.\n");
		return 1;
	}
	if (grid[29] == 'O' && grid[83] == 'O' && grid[137] == 'O') {
		printf("\nPlayer 2 won.\n");
		return 1;
	}
	if (grid[33] == 'O' && grid[87] == 'O' && grid[141] == 'O') {
		printf("\nPlayer 2 won.\n");
		return 1;
	}
	if (grid[25] == 'O' && grid[83] == 'O' && grid[141] == 'O') {
		printf("\nPlayer 2 won.\n");
		return 1;
	}
	if (grid[33] == 'O' && grid[83] == 'O' && grid[133] == 'O') {
		printf("\nPlayer 2 won.\n");
		return 1;
	}

	return 0;
}

void Play(char grid[]) {
	char choice = '?';
	int i;
	
	printf(grid);
	printf("\n\n");

	while (choice != '0') {
		for (i = 1; i < 10; ++i) {
			printf("\nPick a cell: ");
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
			if (GameOver(grid)) {
				break;
			}
		}
		if (i == 10)
			printf("\nIt's a draw.\n");
		printf("\nTo play new game enter any key; enter \"0\" to exit: ");
		scanf(" %c", &choice);
		RestartGrid(grid);
	}
}