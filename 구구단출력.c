#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int i;

	 while(1){
		 printf("2���� 9���� ���ڸ� �Է����ּ���(1�� ������ ���α׷��� ����˴ϴ�): ");
		 scanf("%d", &n);

		if (n == 1) {
			 printf("\n���α׷��� �����մϴ�\n");
			 break;
		 }
		if (n < 2 || n>9) {
			printf("\n���� ���� �����Դϴ�\n\n");
			continue;
		}
			 
		 for (i = 1; i <= 9; i++)
			 printf("%d * %d = %d\n", n, i, n * i);
		 printf("\n");
	 }

}