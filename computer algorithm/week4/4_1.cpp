//���� : ���� ����Ͽ�  �Լ��� �����ϱ�

#include <stdio.h>
#define SIZE 6

void spans(int x[], int S[]) {
	int s;
	for (int i = 0; i < SIZE; i++) {
		s = 1;
		while ((s <= i) && (x[i - s] <= x[i]))  //�̰� ���ǹ� ���� ����� �ϱ�
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