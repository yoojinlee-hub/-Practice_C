#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, 
//�� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
//��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.
int main(void) {
	char str[100];
	char alphaS[27], alphaB[27];
	int strN[26] = { 0 };
	int sizeStr, max, count = 1;
	int i, j;

	scanf("%s", str);
	sizeStr = strlen(str);

	for (i = 0; i < 26; i++) { //���� ���ڸ� �ε����� ����
		alphaB[i] = 'A' + i; //�빮��
		alphaS[i] = 'a' + i; //�ҹ���
	}
	alphaB[26] = '\0';
	alphaS[26] = '\0';

	for (i = 0; i < sizeStr; i++) 
		for(j=0;j<26;j++)
			if (str[i] == alphaB[j] || str[i] == alphaS[j])
				strN[j]++;
	
		
	max = strN[0];
	for (i = 0; i < 26; i++)
		if (max <= strN[i]) 
			max = strN[i];
	
	for (i = 0; i < 26; i++)
		if (max == strN[i]) { //���� �ܾ 2�� �̻��̸� count�� 2 �̻�
			count++; //�⺻ 2
			j = i;
		}

	if (count > 2)
		printf("?");
	else //���� ū ���� �� �ε���?
		printf("%c", alphaB[j]);
	
		
}