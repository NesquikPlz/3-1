//����׷��� ������ķ� ������
//����׷����� �����Ἲ �˻�

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct {
	int n, m;	//m�� �����̰� n�� ������?
	int adjMat[SIZE][SIZE];//����������1������0;����׷����� ���Ī
}GraphType;

//cf: ������׷������� Ȯ���Ҷ� �ϳ��� ���� a���� �ٸ� ��� ���� �����ִ��� Ȯ���ϰ�
//���� �� �ݴ�� �ٲ㼭 �ٽ� a���� �ٸ��ֵ� �� ���ٰ������� Ȯ���غ��� ��
//����������

void init(GraphType* g) {
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++)
			g->adjMat[row][col] = 0;
	}
}

void insertEdge(GraphType* g, int start, int end) {
	if ((start >= g->n) || (end >= g->n)) {
		printf("������ �߰��� �� �����ϴ�. \n");
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
	printf("����[%d] ", v + 1);
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
	printf("������ ������ ������ �Է��ϼ���:\n");
	scanf("%d %d", &g.n, &g.m);//n�� ���� m�� ����

	for (int i = 0; i < g.m; i++) {
		scanf("%d %d", &start, &end);
		insertEdge(&g, start - 1, end - 1);
	}
	printAdjMat(&g);
	int visited[SIZE] = { FALSE };
	printf("\n���� �켱 Ž���� ������ ���� �Է�:");
	scanf("%d", &v);
	printf("\n");
	dfsMat(&g, visited, v - 1);
	printf("\n");
	revMat(&g, v);

	printf("\n");
}