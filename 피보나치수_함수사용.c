/****************
20191770 ������ ��ǻ���а� 3�г� //////��ƴ�!!!!!!!!
****************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printFibo(int n);

int main(void) {
	int num, i;
	
	printf("��� �Ǻ���ġ �������� ����ұ��?(3���� ū ����):");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
		printFibo(i);

	printf("\n");
	return 0;
}
void printFibo(int n)//(n+1)��° ���� ���
{
	int f1=1,f2=1,f3,i;

	if (n < 2)
		printf("1 ");
	else if (n == 2)
		printf("2 ");
	else {
		for (i = 2; i <= n; i++) {
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		printf("%d ", f3);
	}

	return;
}