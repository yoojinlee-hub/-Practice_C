#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
0 �̻� 99������ ������ �Է� �ް�, �� �ڸ����� ���� ���մϴ�.
9 ������ ���� �״�� ����մϴ�.
�Է� ���� ���� ���� ������ �ڸ����� �տ��� ���� ���� ���� ������ �ڸ����� �̾� �ٿ� ���ο� ���� ���� �մϴ�.
���ο� ���� 1, 2�� �ݺ��Ͽ� ������ ���ڷ� ���ư� �� ���� �� ���� ������ ���ľ� �ϴ��� ����ϴ� ���α׷��� �ۼ��غ�����.
*/
int makeNewNum(int n) {
	int sum = 0, temp = n;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	sum = sum % 10;
	sum += (temp % 10) * 10;
	return sum;
}
int main(void) {
	int n, temp, count = 0;
	int newNum = 0;

	scanf("%d", &n);

	temp = n;
	do{
		newNum = makeNewNum(n);
		n = newNum;
		count++;
	}while (newNum != temp);

	printf("%d", count);
}