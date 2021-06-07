//응용문제: 행렬에서 특정 원소 찾기

#include <stdio.h>
#include <stdlib.h>

#include <time.h>  //난수생성용
#define ROWS 8
#define COLS 8


void makeArray(int A[][COLS]) {
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			A[r][c] = rand() % 100;	//0부터 99사이의 수
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

int findROW(int A[], int key) {
	for (int c = 0; c < COLS; c++) {
		if (A[c] == key)
			return c;
	}
	return -1;
}

void findMatrix(int A[][COLS], int key) {
	int r = 0;
	int index;

	while (r < ROWS) {
		index = findROW(A[r], key);
		if (index >= 0) {
			printf("%d행 %d열에서 %d발견\n", r, index, key);
			return;
		}
		else
			r++;
	}
	printf("Not Found\n");
}

void main() {
	int A[ROWS][COLS];
	srand(time(NULL));
	makeArray(A);
	printArray(A);

	int key;
	printf("Input a key value :");
	scanf("%d", &key);
	findMatrix(A, key);
}