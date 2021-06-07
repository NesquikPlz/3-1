//week5 가져와서 사용했음
//제자리힙정렬 구현
//최소힙사용, 내림차순정렬함

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

typedef struct {
	int heap[MAX];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void upHeap(HeapType* h) {
	int i = h->heap_size;
	int key = h->heap[i];
	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}

void downHeap(HeapType* h) {
	int temp = h->heap[1];
	int parent = 1, child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))	//child오른쪽노드가 존재하는지 확인
			child++;
		if (temp <= h->heap[child])
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
}

void insertItem(HeapType* h, int key) {
	h->heap_size++;
	h->heap[h->heap_size] = key;
	upHeap(h);
}

int removeMin(HeapType* h) {
	int key = h->heap[1];
	h->heap[1] = h->heap[h->heap_size];
	h->heap_size -= 1;
	downHeap(h);
	return key;
}

void printHeap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
	printf("\n\n");
}

void heapSort(HeapType* h, int list[]) {
	HeapType heap;
	init(&heap);
	for (int i = 1; i <= h->heap_size; i++) {
		heap.heap[i] = h->heap[i];
		heap.heap_size++;
	}
	for (int i = 1; i <= h->heap_size; i++)
		list[i] = removeMin(&heap);

}

void printArray(int list[], int n) {
	for (int i = 1; i <= n; i++)
		printf("[%d] ", list[i]);
	printf("\n");
}

//아니근데 의사코드랑 너무 다르게 지멋대로 코드 아님?! 이럴거면 의사코드 왜작성하?
void inPlaceHeapSort(HeapType* h) {
	int size = h->heap_size;
	int key;
	for (int i = 0; i < size; i++) {
		key = removeMin(h);
		h->heap[h->heap_size + 1] = key;
	}
}

void main() {
	HeapType heap;
	int list[MAX] = { 0 };
	srand(time(NULL));
	init(&heap);
	for (int i = 0; i < 15; i++)
		insertItem(&heap, rand() % 100+1);

	printHeap(&heap);
	getchar();
	inPlaceHeapSort(&heap);
	for (int i = 1; heap.heap[i] > 0; i++)
		printf("[%d] ", heap.heap[i]);

}