//�׷���; ��������Ʈ ������ ����
//�ٵ� �̰Ŵ� �� �����ؼ� ���� �̷��� ���� ���Ѵ�
//Ư�� ������ ����� �������� ã�Ⱑ ���
//��������Ʈ�� ������� ���� ��

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char vName;//����
}Vertex;

typedef struct {//������ �̸� ���� ��ȣ�� �پ��ֳ�
	int eNo;//����
	int weight;//����ġ
	Vertex v1, v2;//��������
}Edge;

typedef struct {
	Vertex v[10];
	Edge e[30];
	int vCount;
	int eCount;
}Graph;

void init(Graph* G) {
	G->vCount = G->eCount = 0;
}

void makeVertex(Graph* G) {
	G->v[G->vCount++].vName = 97 + G->vCount;//���ĺ����������������
}

void insertEdge(Graph* G, int w, Vertex v1, Vertex v2) {
	G->e[G->eCount].eNo = G->eCount;
	G->e[G->eCount].weight = w;
	G->e[G->eCount].v1 = v1;
	G->e[G->eCount].v2 = v2;
	G->eCount++;
}

int main() {
	Graph G;
	init(&G);
	for (int i = 0; i < 6; i++)
		makeVertex(&G);

	insertEdge(&G, 1, G.v[0], G.v[1]);
	insertEdge(&G, 1, G.v[0], G.v[2]);
	insertEdge(&G, 1, G.v[0], G.v[3]);
	insertEdge(&G, 2, G.v[0], G.v[5]);
	insertEdge(&G, 1, G.v[1], G.v[2]);
	insertEdge(&G, 4, G.v[2], G.v[4]);
	insertEdge(&G, 3, G.v[4], G.v[5]);

}