#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char input[100];
	int count = 1, sum = 0;
	int i;

	printf("OX������ ����� �Է����ּ���(ex.OOXOXXO):");
	scanf("%s", input);
	
	for (i = 0; input[i] != '\0'; i++) {
		if (input[i] == 'O') {
			sum += count;
			count++;
		}
		else
			count = 1;
	}
	printf("%d", sum);
}