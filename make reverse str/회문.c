#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int isitReverse(char* arr) {
	int size = strlen(arr);
	int i;

	for (i = 0; i < size/2; i++)
		if (arr[i] != arr[size - 1 - i])
			return 0;
	return 1;
}
int main(void) {
	char* input = (char*)malloc(sizeof(char) * 100);

	printf("�ܾ �Է����ּ���:");
	scanf("%s", input);

	if (isitReverse(input))
		printf("%s(��)�� ȸ���Դϴ�\n", input);
	else
		printf("%s(��)�� ȸ���� �ƴմϴ�\n", input);
}