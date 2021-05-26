//누적평균구하기

#include <stdio.h>
#include <stdlib.h>

#include <time.h>  //난수생성용
#define SIZE 8

void makeArray(int A[]) {
	for (int i = 0; i < SIZE; i++)
		A[i] = rand() % 50 + 50;
}

void printArray(int A[]) {
	for (int i = 0; i < SIZE; i++) {
		printf("[%d] ", A[i]);
	}
	printf("\n");
}

//프린트에없는 알고리즘인가??
//그리고 교수님은 누적평균 구하기코드2개 갈쳐줬는데 그 하나는 멍청코드라서 그냥 이거만 씀
void prefixAvg1(int A[]) {
	int X[SIZE];
	int sum=0;
	for (int i = 0; i < SIZE; i++) {
		sum += A[i];
		X[i] = sum / (i + 1);
	}
	printArray(X);
}

void main() {
	int A[SIZE];
	srand(time(NULL));
	makeArray(A);
	printArray(A);
	getchar();
	prefixAvg1(A);

}