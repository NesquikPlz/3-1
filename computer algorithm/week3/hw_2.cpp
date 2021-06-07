//��������ũ����_ �迭ver1

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void buildList(int A[], int n) {
	for (int r = 0; r < n; r++)
		A[r] = r + 1;
}

int runSimulation(int A[], int n, int k) {
	int r = 0;
	int N = n;
	while (n > 1) {
		int i = 0;
		while (i < k) {
			r = (r + 1) % N;
			if (A[r] != 0)
				i += 1;
		}
		printf("%d\n", A[r]);
		A[r] = 0;
		n -= 1;
		while (A[r] == 0)
			r = (r + 1) % N;
	}
	return A[r];
}

int candle(int A[], int n, int k) {
	buildList(A, n);
	return runSimulation(A, n, k);
}

void main() {
	int A[SIZE] = { 0 };

	int num, key;
	printf("���� ������ ������ �Է��ϼ���:\n");
	scanf("%d %d", &num, &key);

	printf("\nƯ�� ���ʴ� %d��°�� �ֽ��ϴ�\n", candle(A, num, key));
}