#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void findOverlap(char* s, char* s2) {
	int i, j = 0, count = 1, tmp = 0, cnt = 0;

	for (i = 0; s[i] != '\0';) {
		if (s[i] == s[i + 2] && s[i + 1] == s[i + 3]) {
			count += 1;
			i += 2;
			cnt = 1; //�� �� ������ ������ ����
		}
		else if (count != 1 && cnt == 1) { //�� �� ������ ������ Ȯ���ϰ� ����
			s2[j++] = count + '0';
			s2[j++] = s[i];
			s2[j++] = s[i + 1];
			count = 1;
			tmp = 1; //���� �� �� ����
			cnt = 0;
			i++;
		}
		else if (cnt == 0 && tmp == 0) { //�� �� ������ ���� �͵� ���� ���� �� ���� ����
			s2[j++] = s[i];
			s2[j++] = s[i + 1];
			i += 2;
		}
		else if (tmp == 0) { //������ ���� ������
			s2[j++] = s[i];
			count = 1;
			i += 1;
		}
		else if (tmp == 1) {//�� �� ������ ������ �ְ� �����
			tmp = 0;
			i += 1;
		}

	}
	s2[j] = '\0';
}
int main(void) {
	char input[1000], output[1000];

	scanf("%s", input);

	findOverlap(input, output);

	printf("%s", output);
	printf("\n%d", strlen(output));
}