
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void generateData();
void printData();
int totalData();
int maxData();
int data[10]; //��� ���࿡ ����� ���� ����

int main(void) {
	srand(200);
	generateData();

	printf("�߻��� 10���� ����:\n");
	printData();

	printf("10�� ������ �� = %d\n", totalData());
	printf("10�� ������ ���� ū �� =%d\n", maxData());
}
//generateData�Լ��� data[0]-[9]�� ������ �ִ´�
void generateData() {
	int k;
	int* p;
	p = data; // Ȥ�� p = &data[0]
	for (k = 0; k < 10; k++) {//Index 0..9���� ���� �ο�
		*p = rand() % 100;
		p++;
	}
}
//printData �Լ��� data[0]���� data[9]�� �� ���
void printData() {
	int* pi = data;
	int i;

	for (i = 0; i < 10; i++)
		printf("%d ", *pi++);
	printf("\n");
}
//totalData�� ���� ��� ���� �� ����� ��ȯ�Ѵ�
int totalData() {
	int* pi = data, sum = 0;
	int i;

	for (i = 0; i < 10; i++)
		sum += *pi++;

	return sum;
}
int maxData() {
	int* p = data, max = *p;
	int i;

	for (i = 0; i < 10; i++) {
		if (*p >= max)
			max = *p;
		p++;
	}
	return max;
}
