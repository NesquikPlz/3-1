//응용문제: 교차 선분
//나중에 혼자 다시 해보기

#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef struct {
	int num;
	float s, e;
}Segment;

typedef struct {
	float coor;
	char code;
	int id;
}Event;

typedef struct {
	int id1, id2;
}InterSegment;

void insertion_sort(Event ev[], int n) {//되게호로록잘하네교수님
	int i, j;
	Event item;
	for (i = 1; i < n; i++) {
		item = ev[i];
		for (j = i - 1; j >= 0 && ev[j].coor > item.coor; j--)
			ev[j + 1] = ev[j];
		ev[j + 1] = item;
	}
}

void findIntersectingSegment(Event ev[]) {
	int openSegments[MAX];
	InterSegment is[MAX * 2];
	int oCnt = 0; //열린 segment의 개수
	int iCnt = 0; //교차된 segment의 개수

	for (int i = 0; i < MAX * 2; i++) {
		if (ev[i].code == 'S') {
			for (int j = 0; j < oCnt; j++) {
				if (openSegments[j] != 0) {
					is[iCnt].id1 = openSegments[j];
					is[iCnt].id2 = ev[i].id;
					iCnt++;
				}
			}
			openSegments[oCnt++] = ev[i].id;
		}
		else {
			for (int j = 0; j < oCnt; j++) {
				if (openSegments[j] == ev[i].id)
					openSegments[j] = 0;	//선분끝나면 0으로
			}
		}
	}
	for (int i = 0; i < iCnt; i++)
		printf("(%d, %d) ", is[i].id1, is[i].id2);
	printf("\n");
}

int main() {
	Segment lines[] = { {1, 1.0, 3.2}, {2, 0.8, 3.0}, {3, 0.6, 2.8}, {4, 1.1, 2.0}, {5, 5.4, 7.0}, {6, 2.9, 5.0} };
	Event ev[MAX * 2];
	for (int i = 0; i < MAX; i++)
		printf("%d. (%.1f~%.1f)\n", lines[i].num, lines[i].s, lines[i].e);
	printf("\n");

	for (int i = 0, j=0; i < MAX * 2; i++, j++) {
		ev[i].coor = lines[j].s;
		ev[i].code = 'S';
		ev[i++].id = lines[j].num;
		ev[i].coor = lines[j].e;
		ev[i].code = 'E';
		ev[i].id = lines[j].num;
	}
	for (int i = 0; i < MAX * 2; i++)
		printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
	printf("\n");

	insertion_sort(ev, MAX * 2);
	for (int i=0; i<MAX*2; i++)
		printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
	printf("\n");
	
	findIntersectingSegment(ev);

	return 0;
}