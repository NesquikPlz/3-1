//응용문제:신부와반지
//못풀겠음 젠장 
//꼭풀기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int partition(int list[], int key, int left, int right) {
	int tmp;
	int p;
	for (int i = left; i <= right; i++) {
		if (list[i] == key) p = i;
	}
	SWAP(list[left], list[p], tmp);
	while (left < right) {
		while (list[left] < list[p]) left++;
		while (list[right] > list[p]) right--;
		if (left < right) SWAP(list[left], list[right], tmp);
	}while (left < right);
	SWAP(list[right], list[p], tmp);
	return right;
}

void match(int bride[], int l1, int r1, int ring[], int l2, int r2) {
	int b, r;
	if (l1 >= r1 || l2 >= r2) return;
	int first = bride[l1];
	int firstring = partition(ring, first, l2, r2);
	int firstbride = partition(bride, firstring, l1, r1);
	match(bride, l1, firstbride - 1, ring, l2, firstring - 1);
	match(bride, firstbride+1, r1, ring, firstring+1, r2);
}

void main() {
	int bride[MAX];
	int ring[MAX] = { 0 };
	int rand2 = 0;
	srand(time(NULL));

	for (int i = 0; i < MAX; i++) {	//신부리스트랑 반지리스트 초기화
		int randnum = rand() % 99 + 1;
		bride[i] = randnum;

		do rand2 = rand() % 15; while (ring[rand2]);	//반지리스트 빈자리 랜덤으로 선택하기
		ring[rand2] = bride[i];
	}

	printf("<신부>\n");
	for (int i = 0; i < MAX; i++)
		printf("[%d] ", bride[i]);
	printf("\n\n");

	printf("<반지>\n");
	for (int i = 0; i < MAX; i++)
		printf("[%d] ", ring[i]);
	printf("\n\n");

	match(bride, 0, MAX - 1, ring, 0, MAX - 1);
	for (int i = 0; i < MAX; i++)
		printf("%d %d\n", bride[i], ring[i]);


}