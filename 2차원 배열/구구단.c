#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int gugu[8][9];
	int i, j;
	int num;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 9; j++)
			gugu[i][j] = (i + 2) * (j + 1);
	
	printf("--������ ǥ�� ������ �����ϴ�\n");
	for (i = 0; i < 8; i++)
		for (j = 0; j < 9; j++) {
			if (j == 8)
				printf("%3d\n", gugu[i][j]);
			else
				printf("%3d", gugu[i][j]);
		}

	printf("--���ϴ� ��������?");
	scanf("%d", &num);
	for (j = 0; j < 9; j++)
		printf("%3d", gugu[num-2][j]);
	printf("\n");
}