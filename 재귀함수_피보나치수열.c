/*****************
* LAB4_3 ������ 20191770 ��ǻ���а� 2�г�
*******************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n);
int main(void) {
	int n, idx;

	printf("��� �Ǻ���ġ �������� ����ұ��?(3���� ū ����):");
	scanf("%d", &n);

	for (idx = 0; idx < n; idx++) {
		printf("%10d ", fibo(idx));
		if ((idx + 1) % 5 == 0) //�� �ٿ� 5���� ���
			printf("\n");
	}
}

int fibo(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}