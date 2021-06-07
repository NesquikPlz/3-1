//스팬 : 정의 사용하여  함수로 구현하기

#include <stdio.h>
#define SIZE 6

void spans(int x[], int S[]) {
	int s;
	for (int i = 0; i < SIZE; i++) {
		s = 1;
		while ((s <= i) && (x[i - s] <= x[i]))  //이거 조건문 이해 제대로 하기
			s++;
		S[i] = s;
	}
}

void main() {
	int x[SIZE] = { 6, 3, 4, 2, 5, 3 };
	int S[SIZE] = { 0 };

	spans(x, S);
	for (int i = 0; i < SIZE; i++)
		printf("[%d] ", S[i]);
	printf("\n");
}