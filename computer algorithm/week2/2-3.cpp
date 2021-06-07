//동전다루는 문제랑 비슷하다고 함(뭐더라)
//거듭제곱 재귀적으로 구하는 문제

#include <stdio.h>
#include <stdlib.h>

int iter_power(int x, int n) {		//반복으로 거듭제곱 구하기
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

int recur_power(int x, int n) {
	if (n == 0)
		return 1;
	else if (n % 2 == 0) {
		return recur_power(x * x, n / 2);
	}
	else
		return x * recur_power(x * x, (n - 1) / 2);
}

void main() {
	printf("2 ^ 10 = %d\n", iter_power(2, 10));
	printf("2 ^ 10 = %d\n", recur_power(2, 10));

}

//ps) 피보나치는 재귀적으로 정의되어있지만 재귀적으로 코드짜면 존나느림
//왜냐면 중복계산해야되는게 엄청많기떄문