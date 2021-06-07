//응용문제:색분리

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void partition(char list[], int left, int right) {
	int low = left - 1;
	int high = right + 1;
	int tmp;
	
	do {
		do low++; while (list[low] == 'B');
		do high--; while (list[high] == 'R');

		if (low < high)
			SWAP(list[low], list[high], tmp);
		printf("\nlow = %d, high = %d\n", low, high);
		for (int i = 0; i < MAX; i++)
			printf("[%c] ", list[i]);
		printf("\n");
	} while (low < high);
}

void main() {

	char list[MAX];
	srand(time(NULL));

	for (int i = 0; i < MAX; i++) {
		if (rand() % 2) list[i] = 'B';
		else list[i] = 'R';
	}

	for (int i = 0; i < MAX; i++)
		printf("[%c] ", list[i]);
	printf("\n\n");
	getchar();

	partition(list, 0, MAX - 1);
	printf("\n");
	for (int i = 0; i < MAX; i++)
		printf("[%c] ", list[i]);
	printf("\n");
	
}