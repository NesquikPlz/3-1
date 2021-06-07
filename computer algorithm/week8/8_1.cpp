//quicksort
//pivot �� �����ΰŶ� �������ΰŶ� �ΰ�����(�Ѵ� ���ڸ���)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right) {
	int pivot, tmp, low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do low++; while (list[low] < pivot);
		do high--; while (list[high] > pivot);
		printf("\n%d �� %d �ڸ� switch\n", list[low], list[high]);
		if (low<high)
			SWAP(list[low], list[high], tmp);
	} while (low < high);
	SWAP(list[left], list[high], tmp);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);	//q�� ��ġ Ȯ���� ��
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int inplace_partition(int list[], int left, int right, int k) {
	int pivot, tmp, low, high;
	low = left-1;
	high = right;
	pivot = list[k];
	SWAP(list[k], list[right], tmp);
	do {
		do low++; while (list[low] < pivot);
		do high--; while (list[high] > pivot);
		printf("\n%d �� %d �ڸ� switch\n", list[low], list[high]);
		if (low < high)
			SWAP(list[low], list[high], tmp);
	} while (low < high);
	SWAP(list[low], list[right], tmp);
	return low;
}


void inplace_quick_sort(int list[], int left, int right) {
	if (left < right) {
		int k = rand() % (right - left) + left + 1;		//ȣ��
		int q = inplace_partition(list, left, right, k);	//q�� ��ġ Ȯ���� ��
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

void main() {
	int list[MAX];
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
		list[i] = rand() % 100 + 1;
	for (int i = 0; i < MAX; i++)
		printf("[%d] ", list[i]);
	printf("\n\n");
	getchar();

	inplace_quick_sort(list, 0, MAX - 1);
	for (int i = 0; i < MAX; i++)
		printf("[%d] ", list[i]);
}