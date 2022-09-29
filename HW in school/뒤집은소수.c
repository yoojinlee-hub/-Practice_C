#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isitPrime(int n) {
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}
int makeReverse(int input) {
	int reverse = 0, temp = 0;
	while (input > 0) {
		temp = input % 10;
		reverse = reverse * 10 + temp;
		input /= 10;
	}
	return reverse;
}
int main(void) {
	int input, arr[100];
	int i = 0, n = 0, count = 0;

	printf("�Է¹��� ������ ������ �Է����ּ���:");
	scanf("%d", &n);
	
	while (n > 0) {
		printf("�� %d��° ���ڸ� �Է����ּ���:", i++ + 1);
		scanf("%d", &input);

		if (isitPrime(makeReverse(input)))
			arr[count++] = input;

		n--;
	}
	for(i=0;i<count;i++)
		printf("%d ",arr[i]);
}