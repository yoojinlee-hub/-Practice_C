//LAB(1���������Ҵ�)
//20191770 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int* arr, int size) {
	int i;
	for (i = 0; i < size; i++)
		arr[i] = rand() % 999;
}
void printArray(int* arr, int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}
int main(void) {
	int n;
	srand(time(NULL));

	printf("Enter a number:");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	
	initArray(arr, n);
	printArray(arr, n);
	free(arr);
}