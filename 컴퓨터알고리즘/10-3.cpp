//응용문제 : 배열의 두 수 덧셈
//이 전 응용문제 단일모드배열어쩌구도 풀어보기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

typedef struct {
	int elem;
	int idx;
}Dict;

void sort(Dict D[]) {	//insertion sort
	int elem, i, j, idx;
	for (i = 1; i < SIZE; i++) {
		elem = D[i].elem;
		idx = D[i].idx;
		for (j = i - 1; j >= 0 && D[j].elem > elem; j--) {
			D[j + 1].elem = D[j].elem;
			D[j + 1].idx = D[j].idx;
		}
		D[j + 1].elem = elem;
		D[j + 1].idx = idx;
	}
}

int findElement(Dict D[], int v) {
	int i = 0;
	while (D[i].elem <= v && i <= SIZE) {
		if (D[i].elem == v) return i;
		else i++;
	}
	return -1;
}

void findIndexPair(Dict D[], int A[], int s) {
	int j;
	for (int i = 0; i < SIZE; i++) {
		int v = s - A[i];
		j = findElement(D, v);
		if (j != -1) {
			printf("(%d, %d) 이거랑 (%d, %d) 이거임\n", A[i], i, D[j].elem, D[j].idx);
			return;
		}
	}
	if (j == -1) {
		printf("Not Found\n");
	}
}

void buildDict(Dict D[], int A[]) {
	for (int i = 0; i < SIZE; i++) {
		D[i].elem = A[i];
		D[i].idx = i;
	}
	sort(D);
}

int main() {
	int A[SIZE] = { 2, 21, 8, 3, 5, 1, 13, 1 };
	Dict D[SIZE];

	buildDict(D, A);

	for (int i = 0; i < SIZE; i++)
		printf("(%d, %d) ", D[i].elem, D[i].idx);
	printf("\n");

	findIndexPair(D, A, 26);

	return 0;
}