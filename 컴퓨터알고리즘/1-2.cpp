//비트행렬에서 최대 1행 찾기

#include <stdio.h>
#include <stdlib.h>

#include <time.h>  //난수생성용
#define ROWS 8
#define COLS 8


void makeArray(int A[][COLS]) {
	for (int r = 0; r < ROWS; r++) {
		int count = rand() % 8;
		for (int i = 0; i < count; i++) 
			A[r][i] = 1;
		for (int j = count; j < COLS; j++)
			A[r][j] = 0;
	}
}

void mostOnesButSlow(int A[][COLS]) {
	int jmax = 0;
	int i, j, row;
	for (i = 0; i < ROWS; i++) {
		j = 0;
		while ((j < COLS) && (A[i][j] == 1))
			j++;
		if (j > jmax) {
			row = i;
			jmax = j;
		}
	}
	printf("%d행에 %d개의 1이 최대값임\n", row, jmax);
}

int mostOnes(int A[][COLS]) {
	int i = 0, j = 0;
	int row;

	while(1) {
		while (A[i][j] == 1) {
			j++;
			if (j == COLS - 1)
				return i;
		}
		row = i;					
		while (A[i][j] == 0) {
			i++;
			if (i == COLS - 1)
				return row;
		}
	}
}

void printArray(int A[][COLS]) {
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			printf("%2d ", A[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void main() {
	int A[ROWS][COLS];
	srand(time(NULL));
	makeArray(A);
	printArray(A);
	getchar();

	printf("최대 1행은 %d행 입니다.\n", mostOnes(A));
}