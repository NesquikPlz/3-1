//print digit
//재귀적 곱하기랑 나누기(다른 응용문제)는 안풀어주신대

#include <stdio.h>
#include <stdlib.h>

void rPrintDigits(int n) {
	if (n<10)
		printf("%d\n", n);
	else {
		rPrintDigits(n/10);
		printf("%d\n",n%10);	//주의!(왜쓰는지헷갈)
	}
}

void printDigits() {
	int n;
	printf("Enter a number :");
	scanf("%d", &n);
	if (n < 0)
		printf("negative!\n");
	else
		rPrintDigits(n);
}

void main() {
	printDigits();
}