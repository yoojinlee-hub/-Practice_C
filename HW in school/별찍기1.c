/****************
20191770 ������ ��ǻ���а� 3�г�
****************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j, k;
	int num;

	printf("Enter a number:");
	scanf("%d", &num);

	if (num != 1) {
		for (i = 1; i <= num; i++) {
			for (j = 1; j <= i; j++)
				printf(" ");
			for (k = num; k >=i; k--)
				printf("*");
			printf("\n");
		}
	}
	else
		printf("*\n");
}