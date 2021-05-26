//selection sort¶û insertion sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>	//sleep ÇÔ¼ö ¾²´Â°Å

#define MAX 15
#define SWAP(x, y, t) ((t) = (x), (x)=(y), (y)=(t))

void selection_sort(int list[], int n) {
	int least, tmp;
	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (int j = i+1; j < n; j++) {
			if(list[j] < list[least])
				least = j;
		}
		SWAP(list[i], list[least], tmp);
	}
}

void insertion_sort(int list[], int n) {
	int i, j, save;
	for (i = 1; i < n; i++) {
		save = list[i];
		for (j = i - 1; j >= 0 && list[j] > save; j--) 
			list[j + 1] = list[j];
		list[j + 1] = save;
	}
}

void main() {
	int list[MAX];
	srand(time(NULL));

	for (int i = 0; i < MAX; i++) {
		list[i] = rand() % 100;
		for (int j = 0; j < i; j++) {
			if (list[i] == list[j])
				i--;
		}
	}
	for (int i = 0; i < MAX; i++)
		printf("%d ", list[i]);
	printf("\n\n"); 
	getchar();

	//selection_sort(list, MAX);
	insertion_sort(list, MAX);
	for (int i = 0; i < MAX; i++) {
		printf("%d ", list[i]);
		Sleep(500);			//Àç¹Õ¾î
	}
	printf("\n\n");
}

