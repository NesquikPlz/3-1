//개방주소법 알고리즘
//Bucket을 여러개의 slot형태로 이루어지게도 코드짜보기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 13

typedef struct {
	int key;
	int probeCnt;
}Bucket;

typedef struct {
	Bucket A[M];
}HashType;

void initHash(HashType* HT) {
	for (int i = 0; i < M; i++) {
		HT->A[i].key = -1;
		HT->A[i].probeCnt = 0;
	}
}

int h(int k) {
	return k % M;
}

int h2(int k) {
	return 11 - (k % 11);
}

int getNextBucketLinear(int v, int i) {
	return (v + i) % M;
}

int getNextBucketQuadratic(int v, int i) {
	return (v + i*i) % M;
}

int getNextBucketDouble(int v, int i, int key) {
	return (v + i* h2(key)) % M;
}

int isEmpty(HashType* HT, int b) {
	return HT->A[b].key == -1;
}

void insertItem(HashType* HT, int key) {
	int v = h(key);
	int i = 0;
	int cnt = 0;
	while (i < M) {
		cnt++;
		int b = getNextBucketLinear(v, i);
		//int b = getNextBucketQuadratic(v, i);
		//int b = getNextBucketDouble(v, i, key);
		if (isEmpty(HT, b)) {
			HT->A[b].key = key;
			HT->A[b].probeCnt = cnt;
			return;
		}
		else i++;
	}

}

int findElement(HashType* HT, int key) {
	int v = h(key);
	int i = 0;
	int cnt = 0;
	while (i < M) {
		cnt++;
		int b = getNextBucketLinear(v, i);
		if (isEmpty(HT, b)) return 0;
		else if (HT->A[b].key == key)
			return key;
		else i++;
	}
	return 0;
}

int removeElement(HashType* HT, int key) {
	int v = h(key);
	int i = 0;
	int cnt = 0;
	while (i < M) {
		cnt++;
		int b = getNextBucketLinear(v, i);
		if (isEmpty(HT, b)) return 0;
		else if (HT->A[b].key == key) {
			HT->A[b].key = -1;
			HT->A[b].probeCnt = 0;
			return key;
		}
		else i++;
	}
	return 0;
}

void printHashTable(HashType* HT) {
	printf("\nBucket   Key  Probe\n");
	printf("=======================\n");

	for (int i = 0; i < M; i++)
		printf("\nHT[%02d] : %2d   %d\n", i, HT->A[i].key, HT->A[i].probeCnt);
	printf("\n");
}

int main() {
	HashType HT;
	initHash(&HT);

	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		insertItem(&HT, rand() % 90 + 10);
	}
	printHashTable(&HT);
	int key;
	printf("\n탐색할 키 입력:");
	scanf("%d", &key);
	
	if (findElement(&HT, key)) {
		printf("\n키 값 %d이(가) 존재합니다.\n", key);
		removeElement(&HT, key);
		printf("해당 값을 삭제했습니다.\n");
		printHashTable(&HT);
	}
	else
		printf("\n키 값 %d이(가) 존재하지 않습니다.\n", key);
	

	printf("\n");
	return 0;
}