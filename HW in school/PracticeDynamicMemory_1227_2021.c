#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free �Լ��� ����� ��� ����

int main(void) {
	int n;
	int i, sum = 0;
	
	printf("�л��� ��:");
	scanf("%d", &n);
	printf("\n");

	//(intũ��*�Է¹��� ũ��)��ŭ ���� �޸� �Ҵ�
	int* size = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		printf("�л�%d :", i+1);
		scanf("%d", &size[i]);
		sum += (int)size[i];
	}
	printf("\n");
	printf("���: %f\n", (double)(sum / n));

	free(size); //�������� �Ҵ��� �޸� ����
}