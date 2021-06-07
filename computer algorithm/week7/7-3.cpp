//배열을 이용한 합병정렬

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define MAX 15
int sorted[MAX];

void merge(int list[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;		//k도 left로 초기화!!
	int l;
	
	while (i <= mid && j <= right) {
		if (list[i] < list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid) //겨ㅛ수님코드랑 다르게했음
		while (j <= right) sorted[k++] = list[j++];
	else
		while (i <= mid) sorted[k++] = list[i++];
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}


}



void main() {
	int list[MAX];
	srand(time(NULL));
	for (int i = 0; i < MAX; i++) {
		list[i] = rand() % 100 + 1;
		for (int j = 0; j < i; j++) {
			if (list[i] == list[j])
				i--;
		}
	}

	for (int i = 0; i < MAX; i++)
		printf("[%d] ", list[i]);
	printf("\n\n");
	getchar();

	merge_sort(list, 0, MAX - 1);

	printf("\n");
	for (int i = 0; i < MAX; i++) {
		printf("[%d] ", list[i]);
		Sleep(200);
	}
	printf("\n");
}