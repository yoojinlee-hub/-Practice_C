#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char pair[3] = { '(',')' };
	char input[100]; //�Է¹��� ��ȣ��
	int isitPair[100] = {0}; //ä�������� Ȯ���ϴ� �迭
	int i, j = 0, k = 0;

	scanf("%s", input);

	for (i = 0; input[i] != '\0'; i++) {
 		if (input[i] == pair[0]) {
			isitPair[j++] = 1;
		}if (input[i] == pair[1]) {
			if (j - 1 < 0) { k = 1; break; }
			if (isitPair[j-1] == 1) isitPair[j-1]++;
			j--;
		}
	}
	for(i=0;isitPair[i]!=0;i++)
		if (isitPair[i] == 1) {
			k = 1;
			break;
		}
	if (!k) printf("true");
	else printf("false");
}