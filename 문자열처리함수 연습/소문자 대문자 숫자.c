
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<ctype.h>
int main(void)
{
	char string[50]; // �ԷµǴ� ���ڿ��� ����
	char alphaString1[50]; // �Է¹��ڿ����� ���ĺ��� ����
	char alphaString2[50]; // ��ҹ��ڸ� �ٲ�
	char digitString[50];
	char convertedString[50]; // ���ڵ�� ���ڵ�� ��迭�� ���ڿ�
	
	printf("���ڿ��� �Է��ϼ���:");
	fgets(string, sizeof(string), stdin);

	char* p = string;
	char* p1 = alphaString1;
	char* p2 = digitString;

	while (*p != '\n') {
		if (isalpha(*p)) // �Է¹��ڿ����� ���ĺ��� ����
			*p1++ = *p;
		if (isdigit(*p))// �Է¹��ڿ����� ���ڸ� ����
			*p2++ = *p;
		p++;
	}
	*p1 = '\0';
	*p2 = '\0';

	printf("���ڵ��� %s\n", alphaString1);
	printf("���ڵ��� %s\n", digitString);

	int i;
	for (i = 0; i < (int)strlen(alphaString1); i++) {
		if (alphaString1[i] == tolower(alphaString1[i]))
			alphaString2[i] = toupper(alphaString1[i]);
		if (alphaString1[i] == toupper(alphaString1[i]))
			alphaString2[i] = tolower(alphaString1[i]);
	}
	alphaString2[i] = '\0';

	strcpy(convertedString, alphaString1);
	strcat(convertedString, digitString,(int)strlen(digitString));

	printf("��ҹ��ڸ� �ٲ� ���ڵ��� %s\n", alphaString2);
	printf("���ڵ�� ���ڵ�� ��迭�� ���ڿ��� %s\n", convertedString);
}