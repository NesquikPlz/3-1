//arraylist

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
	int V[SIZE];		//이게도대체 뭔 리스트야 그냥 기본배열리스트임? 
	int n;
}ArrayList;

void init(ArrayList* L) {
	L->n = 0;
}

void traverse(ArrayList* L) {
	for (int i = 0; i < L->n; i++) 
		printf("[%d] ", L->V[i]);
	printf("\n");
}

void add(ArrayList* L, int pos, int item) {
	if (L->n == SIZE) {		//예외처리, 함수로 따로 만들어주면 좋다
		printf("fullListException...\n");
		exit(1);
	}
	//invalidPosException... 0<=pos <=L->n 도 추가하기

	for (int i = L->n - 1; i >= pos; i--)
		L->V[i + 1] = L->V[i];
	L->V[pos] = item;
	L->n++;
}

int remove(ArrayList* L, int pos) {
	//exception처리~여기는 invalid랑 empty
	int item = L->V[pos];
	for (int i = pos + 1; i <= L->n - 1; i++)
		L->V[i - 1] = L->V[i];
	L->n--;
	return item;
}

void main() {
	ArrayList list;

	init(&list);
	add(&list, 0, 10); traverse(&list);
	add(&list, 0, 20); traverse(&list);
	add(&list, 1, 30); traverse(&list);
	add(&list, 1, 40); traverse(&list);
	add(&list, 3, 50); traverse(&list);

	getchar();
	remove(&list, 1); traverse(&list);
	remove(&list, 2); traverse(&list);
}