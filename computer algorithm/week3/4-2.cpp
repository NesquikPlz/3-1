//단순연결리스트

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	L->head = NULL;
}

void addFirst(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void addLast(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* p;
	for (p = L->head; p->link != NULL; p = p->link);
	p->link = node;
	node->data = item;
	node->link = NULL;
}

void add(LinkedListType* L, int pos, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	node->data = item;
	node->link = before->link;
	before->link = node;
}


int remove(LinkedListType* L, int pos) {
	ListNode* before = L->head;
	for (int i = 1; i < pos - 1; i++)
		before = before->link;
	ListNode* p = before->link;
	before->link = p->link;
	if (before == L->head) L->head = p->link;
	int data = p->data;
	free(p);
	return data;
}

int removeFirst(LinkedListType* L) {
	ListNode* p = L->head;
	int data = p->data;
	L->head = p->link;
	free(p);
	return data;
}

int removeLast(LinkedListType* L) {
	ListNode* p = L->head;
	ListNode* before;
	while (1) {
		if (p->link == NULL) break;
		before = p;
		p = p->link;
	}
	int data = p->data;
	before->link = NULL;
	free(p);
	return data;
}

int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->data;
}

void set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}

void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d] -> ", p->data);
	printf("NULL\n");
}

void main() {
	LinkedListType list;
	init(&list);

	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);
	getchar();
	add(&list, 1, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);
	addLast(&list, 70); printList(&list);
	getchar();
	printf("\n");
	remove(&list, 1); printList(&list);
	removeFirst(&list); printList(&list);
	removeLast(&list); printList(&list);

	int pos;
	printf("\n몇 번 노드의 값을 반환할까요? ");
	scanf("%d", &pos);
	printf("%d번 노드의 값은 %d\n", pos, get(&list, pos));
}