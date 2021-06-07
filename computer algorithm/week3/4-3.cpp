//연결리스트로 구현한 큐

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
	//엥 이거 뭐지 front랑rear랑 같아야 empty아니었음??
	//front가 공백인게 왜 queue가 비어있는거임?
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
		queue->front = temp->link;//아 front가 첫항을 바로 가리키구나 이거 필기한거 확인해보기
		if (queue->front == NULL)
			queue->rear = NULL;			//오 이거 처리 잊지말고
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
	LinkedQueue queue;	//처음에 선언할때 주소로 선언 안하네 주의주의
	init(&queue);

	enqueue(&queue, 10); print_queue(&queue);
	enqueue(&queue, 20); print_queue(&queue);
	enqueue(&queue, 30); print_queue(&queue);

	dequeue(&queue); print_queue(&queue);
}