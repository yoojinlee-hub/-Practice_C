
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char str[50];
	char birthY[3], gend[2];
	char* birthday, * gender, * age;

	printf("�ֹε�Ϲ�ȣ �Է�<'-'����>:");
	gets(str);

	strncpy(birthY, str, 2);
	birthY[2] = '\0';

	printf("����� ");
	printf(birthY);
	printf("�⵵ ���̱���\n");
	
	birthday = strtok(str, "-");
	gender = strtok(NULL, "\0");
	strncpy(gend, gender, 1);
	gend[1] = '\0';
	
	if (gend[0] == '1') {
		printf("���ں��̽ñ���.\n");
		printf("��� ���� 77�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", (1900+atoi(birthY) + 77));
	}
	else if (gend[0] == '2') {
		printf("���ں��̽ñ���.\n");
		printf("��� ���� 84�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", (1900+atoi(birthY) + 84));
	}
}