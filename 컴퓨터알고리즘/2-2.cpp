//하노이
//손으로 꼭 따라가보래 (재귀 알고리즘 이해하는데 좋다함)

#include <stdio.h>
#include <stdlib.h>

void rHanoi(int n, char from, char aux, char to) {
	if (n == 1)
		printf("Disk %d : Move From %c to %c\n", n, from, to);
	else {
		rHanoi(n - 1, from, to, aux);
		printf("Disk %d : Move From %c to %c\n", n, from, to);
		rHanoi(n - 1, aux, from, to);
	}
}

void main() {
	rHanoi(4, 'A', 'B', 'C');
}