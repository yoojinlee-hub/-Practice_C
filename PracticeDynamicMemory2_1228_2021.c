#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free �Լ��� ����� ��� ����

int findPrime(int num) {
	int i;
	for (i = 2; i < num; i++) 
		if (num % i == 0)
			break;
	if (i == num) //�Ҽ��̴�
		return 1;
	else         //�Ҽ��� �ƴϴ�
		return 0;
	
}
int main(void) {
	int num, i, j;
	int find = 0;

	printf("������ ���� : ");
	scanf("%d", &num);

	int* arr = (int*)malloc(sizeof(int) * num);
	int count = 0;

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
		//�Ҽ��� ���� ����
		if (findPrime(arr[i]) == 1)
			count++;
	}

	free(arr);

	printf("�Ҽ��� ������ %d�Դϴ�.\n", count);

	return 0;
}