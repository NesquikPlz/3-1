//그래프; 간선리스트 구조로 구현
//근데 이거는 좀 복잡해서 보통 이렇게 구현 안한대
//특정 정점의 연결된 간선들을 찾기가 어렵
//인접리스트랑 인접행렬 구현 필

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char vName;//정점
}Vertex;

typedef struct {//간선은 이름 없고 번호가 붙어있네
	int eNo;//간선
	int weight;//가중치
	Vertex v1, v2;//인접정점
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
	G->v[G->vCount++].vName = 97 + G->vCount;//알파벳으로집어넣은거임
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