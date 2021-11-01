#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//���� from�� �׿��ִ� 1���� ������ ���� tmp�� ����Ͽ� ���� to�� �ű��.
void hanoi_tower(int n, char from,char temp, char to) {
	if (n == 1)
		printf("%c %c\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, temp);
		printf("%c %c\n", from, to);
		hanoi_tower(n - 1, temp, from, to);
	}
}
int hanoi_count(int n) {
	if (n == 1)
		return n;
	else
		return hanoi_count(n - 1) + hanoi_count(n - 1) + 1;
}
int main(void) {
	int stencilNum;
	
	scanf("%d", &stencilNum);
	printf("%d\n", hanoi_count(stencilNum));
	hanoi_tower(stencilNum, '1', '2', '3');

}