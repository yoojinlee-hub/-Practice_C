/*****************
* HW4_3_1 ������ 20191770 ��ǻ���а� 2�г�
*******************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int xPower(int x,int y);
int main(void) {
	int x, y;
	printf("Enter two number:");
	scanf("%d %d", &x, &y);

	printf("%d�� %d���� %d�̴�\n", x, y, xPower(x, y));
}
int xPower(int x,int y) {
	if (y == 0)
		return 1;
	else
		return x * xPower(x, y - 1);
}