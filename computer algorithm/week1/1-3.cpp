//������ձ��ϱ�

#include <stdio.h>
#include <stdlib.h>

#include <time.h>  //����������
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

//����Ʈ������ �˰����ΰ�??
//�׸��� �������� ������� ���ϱ��ڵ�2�� ������µ� �� �ϳ��� ��û�ڵ�� �׳� �̰Ÿ� ��
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