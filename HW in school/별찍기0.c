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
		for (i = num; i >= 0; i--) {
			for(j=1;j<=i;j++)
				printf("*");
			printf("\n");
		}
	}else
		printf("*");
}