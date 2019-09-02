#pragma once

int IsTaken(char grid[], char choice) {
	switch (choice) {
	case '1':
		if (grid[25] != '1')
			return 1;
		break;
	case '2':
		if (grid[29] != '2')
			return 1;
		break;
	case '3':
		if (grid[33] != '3')
			return 1;
		break;
	case '4':
		if (grid[79] != '4')
			return 1;
		break;
	case '5':
		if (grid[83] != '5')
			return 1;
		break;
	case '6':
		if (grid[87] != '6')
			return 1;
		break;
	case '7':
		if (grid[133] != '7')
			return 1;
		break;
	case '8':
		if (grid[137] != '8')
			return 1;
		break;
	case '9':
		if (grid[141] != '9')
			return 1;
		break;
	}
	return 0;
}

void UpdateGrid(char grid[], char choice, char c) {
	switch (choice) {
	case '1':
		grid[25] = c;
		break;
	case '2':
		grid[29] = c;
		break;
	case '3':
		grid[33] = c;
		break;
	case '4':
		grid[79] = c;
		break;
	case '5':
		grid[83] = c;
		break;
	case '6':
		grid[87] = c;
		break;
	case '7':
		grid[133] = c;
		break;
	case '8':
		grid[137] = c;
		break;
	case '9':
		grid[141] = c;
		break;
	}
}

void RestartGrid(char grid[]) {
	grid[25] = '1';
	grid[29] = '2';
	grid[33] = '3';
	grid[79] = '4';
	grid[83] = '5';
	grid[87] = '6';
	grid[133] = '7';
	grid[137] = '8';
	grid[141] = '9';
}

void PrintStats() {
	FILE * fptr = NULL;
	fptr = fopen("C:\\Users\\Pietahr\\Desktop\\PROJECTS\\AZ_AI\\PlayerStats.txt", "r");
	char c = '?';

	printf("\n");

	if(fptr != NULL)
		do {
			c = fgetc(fptr);
			printf("%c", c);
		}
		while (c != EOF);
	else {
		printf("\tNo stats yet.\n\n");
		return;
	}
	//fseek(fptr, 0, SEEK_SET);
	if (fptr != NULL)
		fclose(fptr);
}