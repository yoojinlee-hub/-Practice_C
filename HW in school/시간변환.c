#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int input;
	int days = 0, hours = 0, min = 0, sec = 0;

	printf("�� ������ �ð��� �Է����ּ���: ");
	scanf("%d", &input);

	printf("%d��=", input);
	if (input >= 86400) {
		days = input / 86400;
		printf("%d�� ", days);
		input -= 86400 * days;
	}
	if (input >= 3600) {
		hours = input / 3600;
		printf("%d�ð� ", hours);
		input -= 3600 * hours;
	}
	if (input >= 60) {
		min = input / 60;
		printf("%d�� ", min);
		input -= 60 * min;
	}
	if (input >= 0) {
		printf("%d�� ", input);
	}
	printf("\n");
}