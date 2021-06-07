#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15
#define B 10
#define DIGITS 2

typedef int element;
typedef struct {
	element data[MAX];
	int front, rear;
}QueueType;

void init(QueueType* q) {
	q->front = q->rear = 0;
}

int isEmpty(QueueType* q) {
	return q->front == q->rear;
}

int isFull(QueueType* q) {
	return (q->rear + 1) % MAX == q->front;
	//원형큐는 한칸 비워놓음
}

void enqueue(QueueType* q, element item) {
	if(isFull(q)) exit(1);
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (isEmpty(q)) exit(1);
	q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}

void queue_print(QueueType* q) {
	if (!isEmpty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX;
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}

void printB(QueueType queues[]) {
	printf("\n*********************************\n");
	for (int b = 0; b < B; b++) {
		printf("[%d] -> ", b);
		queue_print(&queues[b]);
	}
	printf("\n*********************************\n\n");
}

void radixsort(int list[], int n) {
	int i, b, d, f = 1;
	QueueType queues[B];
	for (b = 0; b < B; b++)
		init(&queues[b]);
	for (d = 0; d < DIGITS; d++) {
		for (int i = 0; i < n; i++)
			enqueue(&queues[(list[i] / f)%10], list[i]);

		printB(queues);
		for (b = i = 0; b < B; b++) {
			while (!isEmpty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		}
		f *= 10;
	}
}

void main() {
	int list[MAX];
	srand(time(NULL));
	for (int i = 0; i < MAX; i++) 
		list[i] = rand() % 90 + 10;
	for (int i = 0; i < MAX; i++)
		printf("[%d] ", list[i]);
	printf("\n\n");

	radixsort(list, MAX);
	for (int i = 0; i < MAX; i++)
		printf("[%d] ", list[i]);
	printf("\n\n");
}