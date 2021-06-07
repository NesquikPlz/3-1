//Floyd-Warshall 알고리즘
//==이행적폐쇄
//인접행렬로 구현

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define INF 1000000

typedef struct GraphType {
	int n;//정점개수
	int weight[SIZE][SIZE];
}GraphType;

int A[SIZE][SIZE];//결과저장배열

void printA(GraphType* g) {//배열출력
	int i, j;
	printf("============================================\n");
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF)
				printf("  * ");
			else
				printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("============================================\n");
}

void floyd(GraphType* g) {
	int i, j, k;
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	}
	printA(g);

	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++) {
			for (j = 0; j < g->n; j++) {
				if (A[i][k] == 1 && A[k][j] == 1)
					A[i][j] = 1;
				/*
				가중치가 있다면 다음과 같이 코드를 작성하자
				if (A[i ][k]+A[k][j]<A[i][j])
					A[i][j] = A[i][k] + A[k][j];
				*/
			}
		}
		printA(g);
	}
}

int main(void) {
	GraphType g = { 5,
		{{0, 1, INF, 1, INF},	//대각선은 loop이고 없으니까 0으로 해놓음
		{INF, 0, INF, INF, INF},//경로 존재하면 1
		{1, INF, 0, INF, INF},
		{INF, INF, INF, 0, 1},
		{1, INF, INF, INF, 0}}
	};
	floyd(&g);
	return 0;
}