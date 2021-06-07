//생일케이크문제_ 배열ver2

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void buildList(int A[], int n) {
	for (int r = 0; r < n; r++)
		A[r] = r + 1;
}

void remove(int A[], int n, int pos) {
	for (int i = pos; i < n; i++)
		A[i] = A[i + 1];
}

int runSimulation(int A[], int n, int k) {
	int r = 0;
	while (n > 1) {
		r = (r + k) % n;
		remove(A, n, r);
		n -= 1;
	}
	return A[0];
}

int candle(int A[], int n, int k) {
	buildList(A, n);
	return runSimulation(A, n, k);
}

void main() {
	int A[SIZE] = { 0 };

	int num, key;
	printf("초의 개수와 간격을 입력하세요:\n");
	scanf("%d %d", &num, &key);

	printf("\n특수 양초는 %d번째에 있습니다\n", candle(A, num, key));
}