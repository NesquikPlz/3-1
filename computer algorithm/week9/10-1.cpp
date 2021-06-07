//���� adt�����̶� insertion sort�� ��� find element �� �׳� find element
//������ �����Ƽ� ���� ���ߴµ� �������� �ڵ庸������
//���߿� �غ���~

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

typedef struct {
	int key;
	char value[10];
}element;		//�̷����ϴ°ű�

typedef struct {
	element dict[MAX];
	int size;
}DictType;

void init(DictType* d) {
	d->size = 0;
}

void insertKey(DictType* d) {
	for (int i = 0; i < MAX; i++) {
		d->dict[i].key = rand() % 30 + 1;
		for (int j = 0; j < i; j++) {
			if (d->dict[i].key == d->dict[j].key)
				i--;
		}
	}
}

void insertValue(DictType* d) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 5; j++)
			d->dict[i].value[j] = rand() % 26 + 97;//ascii
		d->size++;
	}
}

void makeDict(DictType* d) {
	insertKey(d);
	insertValue(d);
}

int rFindElement(DictType* d, int key, int l, int r) {
	int mid;
	if (l <= r) {
		mid = (l + r) / 2;
		if (key == d->dict[mid].key)
			return mid;
		else if (key < d->dict[mid].key)
			return rFindElement(d, key, l, mid - 1);
		else
			return rFindElement(d, key, mid + 1, r);
	}
	return -1;
}

int findElement(DictType* d, int key, int l, int r) {
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (key == d->dict[mid].key)
			return mid;
		else if (key < d->dict[mid].key)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

void printDict(DictType* d) {
	printf("key value \n=========\n");
	for (int i = 0; i < d->size; i++) {
		printf("%2d  ", d->dict[i].key);
		for (int j = 0; j < 5; j++)
			printf("%c", d->dict[i].value[j]);
		printf("\n");
	}
}

void insertion_sort(DictType* d) {//�ǰ�ȣ�η����ϳױ�����
	int i, j;
	element item;
	for (i = 1; i < MAX; i++) {
		item = d->dict[i];
		for (j = i - 1; j >= 0 && d->dict[j].key > item.key; j--)
			d->dict[j + 1] = d->dict[j];
		d->dict[j + 1] = item;
	}
}



int main() {
	DictType d;
	init(&d);
	srand(time(NULL));
	makeDict(&d);
	printDict(&d);//���̰���վ�
	getchar();

	printf("\n");
	insertion_sort(&d);
	printDict(&d);

	int key;
	printf("\n+���+ �˻��� key ���� �Է�:");
	scanf("%d", &key);
	int index = rFindElement(&d, key, 0, MAX - 1);
	if (index == -1)
		printf("�˻�����!\n\n");
	else {
		printf("\n��ġ %d���� Ű : %d, �� : ", index + 1, key);
		for (int j = 0; j < 5; j++)
			printf("%c", d.dict[index].value[j]);
		printf(" �� �˻��Ǿ���\n\n");
	}

	printf("\n\n+�����+ �˻��� key ���� �Է�:");
	scanf("%d", &key);
	index = findElement(&d, key, 0, MAX - 1);
	if (index == -1)
		printf("�˻�����!\n\n");
	else {
		printf("\n��ġ %d���� Ű : %d, �� : ", index + 1, key);
		for (int j = 0; j < 5; j++)
			printf("%c", d.dict[index].value[j]);
		printf(" �� �˻��Ǿ���\n");
	}

	return 0;
}