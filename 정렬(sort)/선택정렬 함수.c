/****************
* LABHW3_5 20191770 ������ ��ǻ���а� 3�г�
************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <time.h>

void initArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		arr[i] = rand() % 100;
	return;
}
void selectionSort(int list[], int size) {
	int i, j, temp, minIndex;

	for (i = 0; i < size - 1; i++) {
		minIndex = i;
		for (j = i+1; j < size; j++) 
			if (list[j] < list[minIndex])
				minIndex = j;
		
		temp = list[i];
		list[i] = list[minIndex];
		list[minIndex] = temp;
	}
}
void printArray(int a[], int size) {
	int i;

	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main(void) {
	int i, a[10];
	srand(time(NULL));
	printf("�߻��� ����:     ");
	initArray(a, 10);
	printArray(a, 10);

	printf("���� ��:        ");
	selectionSort(a, 10);
	printArray(a, 10);
}