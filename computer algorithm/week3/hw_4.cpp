//생일케이크문제_원형연결리스트

#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	L->head = NULL;
}

LinkedListType* buildList(LinkedListType* L, int n) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	L->head = p;
	p->data = 1;
	for (int i = 2; i <= n; i++) {
		p->link = (ListNode*)malloc(sizeof(ListNode));
		p = p->link;
		p->data = i;
	}
	p->link = L->head;
	return L;
}

int runSimulation(LinkedListType* L, int n, int k) {
	ListNode* p = L->head;
	while (p != p->link) {
		for (int i = 1; i < k; i++)
			p = p->link;
		ListNode* pnext = p->link;
		p->link = p->link->link;
		free(pnext);
		p = p->link;
	}
	return p->data;
}

int candle(LinkedListType* L, int n, int k) {
	buildList(L, n);
	return runSimulation(L, n, k);
}

void main() {
	LinkedListType L;
	init(&L);

	int num, key;
	printf("초의 개수와 간격을 입력하세요:\n");
	scanf("%d %d", &num, &key);

	printf("\n특수 양초는 %d번째에 있습니다\n", candle(&L, num, key));
}