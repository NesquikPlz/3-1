//방향그래프 인접행렬로 구현요
//방향그래프의 강연결성 검사

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct {
	int n, m;	//m이 정점이고 n이 간선임?
	int adjMat[SIZE][SIZE];//간선있으면1없으면0;방향그래프라 비대칭
}GraphType;

//cf: 강연결그래프인지 확인할때 하나의 정점 a에서 다른 모든 정점 갈수있는지 확인하고
//방향 다 반대로 바꿔서 다시 a에서 다른애들 다 접근가능한지 확인해보면 됨
//원리가뭐지

void init(GraphType* g) {
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++)
			g->adjMat[row][col] = 0;
	}
}

void insertEdge(GraphType* g, int start, int end) {
	if ((start >= g->n) || (end >= g->n)) {
		printf("간선을 추가할 수 없습니다. \n");
		return;
	}
	g->adjMat[start][end] = 1;
}

void printAdjMat(GraphType* g) {
	printf("\n");
	for (int row = 0; row < g->n; row++) {
		printf("|");
		for (int col = 0; col < g->n; col++)
			printf(" %d ", g->adjMat[row][col]);
		printf("|\n");
	}
}

void dfsMat(GraphType* g, int visited[], int v) {
	visited[v] = TRUE;
	printf("정점[%d] ", v + 1);
	for (int w = 0; w < g->n; w++) {
		if (g->adjMat[v][w] && !visited[w])
			dfsMat(g, visited, w);
	}
}

void revMat(GraphType* g, int v) {
	GraphType r;
	init(&r);
	r.n = g->n;
	int visited[SIZE] = { FALSE };

	for (int row = 0; row < g->n; row++) {
		for (int col = 0; col < g->n; col++)
			r.adjMat[col][row] = g->adjMat[row][col];
	}
	printAdjMat(&r);
	printf("\n");
	dfsMat(&r, visited, v - 1);
}

void main() {
	GraphType g;
	init(&g);
	int n, m, v;
	int start, end;
	printf("정점과 간선의 개수를 입력하세요:\n");
	scanf("%d %d", &g.n, &g.m);//n이 정점 m이 간선

	for (int i = 0; i < g.m; i++) {
		scanf("%d %d", &start, &end);
		insertEdge(&g, start - 1, end - 1);
	}
	printAdjMat(&g);
	int visited[SIZE] = { FALSE };
	printf("\n깊이 우선 탐색을 시작할 정점 입력:");
	scanf("%d", &v);
	printf("\n");
	dfsMat(&g, visited, v - 1);
	printf("\n");
	revMat(&g, v);

	printf("\n");
}