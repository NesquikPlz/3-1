//���Ḯ��Ʈ�� ����� �׷��� ��������Ʈ ����
//�� �����ϴϱ� ����� �����ؾ���
//���빮��:���ã�� Ǯ��(queue�̿��ϸ� ���Ұŷ�)

#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
	int vNum1;
	int vNum2;
	int isTree;
	int weight;
	struct Edge* next;//edge�� ���� ���Ḯ��Ʈ
}Edge;

typedef struct IncidentEdge {
	int adjVertex;//opposite �Լ����
	Edge* e;
	struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex {
	int num;
	int isFresh;
	struct Vertex* next;
	IncidentEdge* top;
}Vertex;

Vertex* vHead = NULL;//�������� �����ߴµ� �����Ⱦ��Ե� �ڵ� ©���־����
Edge* eHead = NULL;
int vCount;
int eCount;

void makeVertices() {
	Vertex* p = (Vertex*)malloc(sizeof(Vertex));
	p->num = ++vCount;
	p->top = NULL;
	p->next = NULL;
	p->isFresh = 0;//0�̸� fresh
	Vertex* q = vHead;
	if (q == NULL)
		vHead = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

Vertex* findVertex(int v) {//v�� ��ġ����; incidentEdge���̶� �������ַ���
	Vertex* p = vHead;
	while (p->num != v)
		p = p->next;
	return p; 
}

void insertIncidentEdge(Vertex* v, int adjv, Edge* e) {
	IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
	p->adjVertex = adjv;
	p->e = e;
	p->next = NULL;
	IncidentEdge* q = v->top;
	if (q == NULL)
		v->top = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

void insertEdge(int v1, int v2) {
	Edge* p = (Edge*)malloc(sizeof(Edge));
	p->vNum1 = v1;//���������ٵ� �̰� �����̶� �������
	p->vNum2 = v2;
	p->isTree = 0;//0�̸� tree�ƴ϶��
	p->next = NULL;
	Edge* q = eHead;
	if (q == NULL)
		eHead = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
	Vertex* v = findVertex(v1);
	insertIncidentEdge(v, v2, p);

	v = findVertex(v2);				//�����̴ϱ� ����⿬�ᤡ
	insertIncidentEdge(v, v1, p);
}

void dfs(Vertex* v) {//���
	IncidentEdge* q;
	if (v->isFresh == 0) {
		printf("[%d] ", v->num);
		v->isFresh = 1;
	}
	for (q = v->top; q != NULL; q = q->next) {
		v = findVertex(q->adjVertex);
		if (v->isFresh == 0) {
			q->e->isTree = 1;
			dfs(v);
		}
	}
}

void print() {
	Vertex* p = vHead;
	IncidentEdge* q;
	for (; p != NULL; p = p->next) {
		printf("���� %d : ", p->num);
		for (q=p->top; q!=NULL; q = q->next)
			printf("[%d] ", q->adjVertex);
		printf("\n");
	}
}

int main() {
	for (int i = 0; i < 9; i++)
		makeVertices();
	insertEdge(1, 2);
	insertEdge(1, 3);
	insertEdge(2, 4);
	insertEdge(2, 5);
	insertEdge(3, 5);
	insertEdge(3, 6);
	insertEdge(4, 7);
	insertEdge(5, 7);
	insertEdge(5, 8);
	insertEdge(6, 8);
	insertEdge(7, 9);
	insertEdge(8, 9);

	print();
	dfs(vHead);
	printf("\n\n");
	return 0;
}