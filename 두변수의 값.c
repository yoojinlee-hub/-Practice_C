#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void change(int *pa, int *pb) {
	int temp = 0;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
	printf("%d %d", *pa, *pb);
}
int main(void) {
	int a, b;
	int* pa = &a;
	int* pb = &b;

	printf("���ڸ� �Է����ּ���:");
	scanf("%d %d", &a, &b);
	change(pa, pb);
}