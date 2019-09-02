#pragma once

void MakeAI(player ** tmpptr) {
	char pName[33] = "AI";
	*tmpptr = (player *)malloc(sizeof(player));
	memcpy((*tmpptr)->name, pName, strlen(pName) + 1);
	(*tmpptr)->w = 0;
	(*tmpptr)->d = 0;
	(*tmpptr)->l = 0;
}

void PlayAgaistAI(char grid[], player * P1, player * P2) {
	char choice = '?';
	int i, cnt = 1;
	while (choice != '0') {
		for (i = 1; i < 10; ++i) {
			printf("\nPick a cell %s: ", ((i + cnt - 1) & 1) ? P1->name : P2->name);
			if (((i + cnt - 1) & 1) == 1) {
				scanf(" %c", &choice);
				while (!isdigit(choice) || choice == '0' || IsTaken(grid, choice)) {
					printf("\nInvalid choice. Choose free cell from 1-9: ");
					scanf_s(" %c", &choice);
				}
			}
			else {
				//always take the center if possible
				if (!IsTaken(grid, '5')) {	//1.25/2.29/3.33/4.79/5.83/6.87/7.133/8.137/9.141
					choice = '5';
					goto Update;
				}
				//if any player has two in a row take remaining cell
				if ((cnt & 1) == 0) {	//prefer 'X' to win
					if (!IsTaken(grid, '1') && ((grid[29] == 'X' && grid[33] == 'X') || (grid[83] == 'X' && grid[141] == 'X') || (grid[79] == 'X' && grid[133] == 'X'))) {
						choice = '1';
						goto Update;
					}
					if (!IsTaken(grid, '2') && ((grid[25] == 'X' && grid[33] == 'X') || (grid[83] == 'X' && grid[137] == 'X'))) {
						choice = '2';
						goto Update;
					}
					if (!IsTaken(grid, '3') && ((grid[25] == 'X' && grid[29] == 'X') || (grid[83] == 'X' && grid[133] == 'X') || (grid[87] == 'X' && grid[141] == 'X'))) {
						choice = '3';
						goto Update;
					}
					if (!IsTaken(grid, '4') && ((grid[25] == 'X' && grid[133] == 'X') || (grid[83] == 'X' && grid[87] == 'X'))) {
						choice = '4';
						goto Update;
					}
					if (!IsTaken(grid, '6') && ((grid[141] == 'X' && grid[33] == 'X') || (grid[83] == 'X' && grid[79] == 'X'))) {
						choice = '6';
						goto Update;
					}
					if (!IsTaken(grid, '7') && ((grid[83] == 'X' && grid[33] == 'X') || (grid[137] == 'X' && grid[141] == 'X') || (grid[79] == 'X' && grid[25] == 'X'))) {
						choice = '7';
						goto Update;
					}
					if (!IsTaken(grid, '8') && ((grid[141] == 'X' && grid[133] == 'X') || (grid[83] == 'X' && grid[29] == 'X'))) {
						choice = '8';
						goto Update;
					}
					if (!IsTaken(grid, '9') && ((grid[87] == 'X' && grid[33] == 'X') || (grid[83] == 'X' && grid[25] == 'X') || (grid[137] == 'X' && grid[133] == 'X'))) {
						choice = '9';
						goto Update;
					}
					//still block if you can't win
					if (!IsTaken(grid, '1') && ((grid[29] == 'O' && grid[33] == 'O') || (grid[83] == 'O' && grid[141] == 'O') || (grid[79] == 'O' && grid[133] == 'O'))) {
						choice = '1';
						goto Update;
					}
					if (!IsTaken(grid, '2') && ((grid[25] == 'O' && grid[33] == 'O') || (grid[83] == 'O' && grid[137] == 'O'))) {
						choice = '2';
						goto Update;
					}
					if (!IsTaken(grid, '3') && ((grid[25] == 'O' && grid[29] == 'O') || (grid[83] == 'O' && grid[133] == 'O') || (grid[87] == 'O' && grid[141] == 'O'))) {
						choice = '3';
						goto Update;
					}
					if (!IsTaken(grid, '4') && ((grid[25] == 'O' && grid[133] == 'O') || (grid[83] == 'O' && grid[87] == 'O'))) {
						choice = '4';
						goto Update;
					}
					if (!IsTaken(grid, '6') && ((grid[141] == 'O' && grid[33] == 'O') || (grid[83] == 'O' && grid[79] == 'O'))) {
						choice = '6';
						goto Update;
					}
					if (!IsTaken(grid, '7') && ((grid[83] == 'O' && grid[33] == 'O') || (grid[137] == 'O' && grid[141] == 'O') || (grid[79] == 'O' && grid[25] == 'O'))) {
						choice = '7';
						goto Update;
					}
					if (!IsTaken(grid, '8') && ((grid[141] == 'O' && grid[133] == 'O') || (grid[83] == 'O' && grid[29] == 'O'))) {
						choice = '8';
						goto Update;
					}
					if (!IsTaken(grid, '9') && ((grid[87] == 'O' && grid[33] == 'O') || (grid[83] == 'O' && grid[25] == 'O') || (grid[137] == 'O' && grid[133] == 'O'))) {
						choice = '9';
						goto Update;
					}
					//the only one missing to make fork if player chooses even cell on 2nd turn(his 1st)
					if (!IsTaken(grid, '4') && i == 5 && grid[137] == 'O') {
						choice = '4';
						goto Update;
					}
				}
				else { //prefer 'O' to win
					if (!IsTaken(grid, '1') && ((grid[29] == 'O' && grid[33] == 'O') || (grid[83] == 'O' && grid[141] == 'O') || (grid[79] == 'O' && grid[133] == 'O'))) {
						choice = '1';
						goto Update;
					}
					if (!IsTaken(grid, '2') && ((grid[25] == 'O' && grid[33] == 'O') || (grid[83] == 'O' && grid[137] == 'O'))) {
						choice = '2';
						goto Update;
					}
					if (!IsTaken(grid, '3') && ((grid[25] == 'O' && grid[29] == 'O') || (grid[83] == 'O' && grid[133] == 'O') || (grid[87] == 'O' && grid[141] == 'O'))) {
						choice = '3';
						goto Update;
					}
					if (!IsTaken(grid, '4') && ((grid[25] == 'O' && grid[133] == 'O') || (grid[83] == 'O' && grid[87] == 'O'))) {
						choice = '4';
						goto Update;
					}
					if (!IsTaken(grid, '6') && ((grid[141] == 'O' && grid[33] == 'O') || (grid[83] == 'O' && grid[79] == 'O'))) {
						choice = '6';
						goto Update;
					}
					if (!IsTaken(grid, '7') && ((grid[83] == 'O' && grid[33] == 'O') || (grid[137] == 'O' && grid[141] == 'O') || (grid[79] == 'O' && grid[25] == 'O'))) {
						choice = '7';
						goto Update;
					}
					if (!IsTaken(grid, '8') && ((grid[141] == 'O' && grid[133] == 'O') || (grid[83] == 'O' && grid[29] == 'O'))) {
						choice = '8';
						goto Update;
					}
					if (!IsTaken(grid, '9') && ((grid[87] == 'O' && grid[33] == 'O') || (grid[83] == 'O' && grid[25] == 'O') || (grid[137] == 'O' && grid[133] == 'O'))) {
						choice = '9';
						goto Update;
					}
					//still block if you can't win
					if (!IsTaken(grid, '1') && ((grid[29] == 'X' && grid[33] == 'X') || (grid[83] == 'X' && grid[141] == 'X') || (grid[79] == 'X' && grid[133] == 'X'))) {
						choice = '1';
						goto Update;
					}
					if (!IsTaken(grid, '2') && ((grid[25] == 'X' && grid[33] == 'X') || (grid[83] == 'X' && grid[137] == 'X'))) {
						choice = '2';
						goto Update;
					}
					if (!IsTaken(grid, '3') && ((grid[25] == 'X' && grid[29] == 'X') || (grid[83] == 'X' && grid[133] == 'X') || (grid[87] == 'X' && grid[141] == 'X'))) {
						choice = '3';
						goto Update;
					}
					if (!IsTaken(grid, '4') && ((grid[25] == 'X' && grid[133] == 'X') || (grid[83] == 'X' && grid[87] == 'X'))) {
						choice = '4';
						goto Update;
					}
					if (!IsTaken(grid, '6') && ((grid[141] == 'X' && grid[33] == 'X') || (grid[83] == 'X' && grid[79] == 'X'))) {
						choice = '6';
						goto Update;
					}
					if (!IsTaken(grid, '7') && ((grid[83] == 'X' && grid[33] == 'X') || (grid[137] == 'X' && grid[141] == 'X') || (grid[79] == 'X' && grid[25] == 'X'))) {
						choice = '7';
						goto Update;
					}
					if (!IsTaken(grid, '8') && ((grid[141] == 'X' && grid[133] == 'X') || (grid[83] == 'X' && grid[29] == 'X'))) {
						choice = '8';
						goto Update;
					}
					if (!IsTaken(grid, '9') && ((grid[87] == 'X' && grid[33] == 'X') || (grid[83] == 'X' && grid[25] == 'X') || (grid[137] == 'X' && grid[133] == 'X'))) {
						choice = '9';
						goto Update;
					}
					//to avoid fork
					if (!IsTaken(grid, '8') && (i == 4) && ((grid[25] == grid[141]) || (grid[33] == grid[133]))) {
						choice = '8';
						goto Update;
					}
					if (!IsTaken(grid, '3') && (i == 4) && (grid[29] == grid[141])) {
						choice = '3';
						goto Update;
					}
					if (!IsTaken(grid, '3') && (i == 4) && (grid[25] == grid[87])) {
						choice = '3';
						goto Update;
					}
				}
				//otherwise
				if (!IsTaken(grid, '7')) {
					choice = '7';
					goto Update;
				}
				if (!IsTaken(grid, '3')) {
					choice = '3';
					goto Update;
				}
				if (!IsTaken(grid, '9')) {
					choice = '9';
					goto Update;
				}
				if (!IsTaken(grid, '1')) {
					choice = '1';
					goto Update;
				}
				if (!IsTaken(grid, '2')) {
					choice = '2';
					goto Update;
				}
				if (!IsTaken(grid, '6')) {
					choice = '6';
					goto Update;
				}
				if (!IsTaken(grid, '8')) {
					choice = '8';
					goto Update;
				}
				if (!IsTaken(grid, '4')) {
					choice = '4';
					goto Update;
				}
			}
			Update:
			if (i & 1)
				UpdateGrid(grid, choice, 'X');
			else
				UpdateGrid(grid, choice, 'O');
			printf("\n\n");
			printf(grid);
			if ((cnt & 1) == 1) {
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