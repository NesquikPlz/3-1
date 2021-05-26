//���Ḯ��Ʈ�� ������ ť

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
	int data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
}LinkedQueue;

void init(LinkedQueue* queue) {
	queue->front = queue->rear = NULL;
}

int is_empty(LinkedQueue* queue) {
	return queue->front == NULL;
	//�� �̰� ���� front��rear�� ���ƾ� empty�ƴϾ���??
	//front�� �����ΰ� �� queue�� ����ִ°���?
}

void enqueue(LinkedQueue* queue, int data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(queue)) {
		queue->front = temp;
		queue->rear = temp;
	}
	else {
		queue->rear->link = temp;
		queue->rear = temp;
	}
}

int dequeue(LinkedQueue* queue) {
	QueueNode* temp = queue->front;
	int data;
	if (is_empty(queue)) {
		fprintf(stderr, "Queue is empty\n");
		exit(1);
	}
	else {
		data = temp->data;
		queue->front = temp->link;//�� front�� ù���� �ٷ� ����Ű���� �̰� �ʱ��Ѱ� Ȯ���غ���
		if (queue->front == NULL)
			queue->rear = NULL;			//�� �̰� ó�� ��������
		free(temp);
		return data;
	}

}

void print_queue(LinkedQueue* queue) {
	QueueNode* p;
	for (p=queue->front; p != NULL; p=p->link)
		printf("[%d] -> ", p->data);
	printf("[NULL]\n");
}

void main() {
	LinkedQueue queue;	//ó���� �����Ҷ� �ּҷ� ���� ���ϳ� ��������
	init(&queue);

	enqueue(&queue, 10); print_queue(&queue);
	enqueue(&queue, 20); print_queue(&queue);
	enqueue(&queue, 30); print_queue(&queue);

	dequeue(&queue); print_queue(&queue);
}