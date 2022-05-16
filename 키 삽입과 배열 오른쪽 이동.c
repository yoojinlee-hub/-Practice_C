#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char after[27];
char newWord[] = "";
int isin(char word[], int size, char key) {
	int count = 0, i;
	for (i = 0; i < size; i++)
		if (word[i] == key)
			return 1; //����
	return 0; //����
}
void remove_duplicated_char(char word[]) {
	int i, j = 0, isinWord;

	for (i = 0; i < strlen(word); i++) {
		isinWord = isin(newWord, j, word[i]);
		if (isinWord == 0)
			newWord[j++] = word[i];
	}
	newWord[j] = '\0';
}
void makeCode(char c[], int distance, char* word)
{
	int i, j, k = 0, m = 0;
	char alpha;
	char temp[27];

	// �ϴ� key�� �ְ�(c�� �պκп�)
	for (i = 0; word[i] != '\0'; i++)
		c[i] = word[i];

	// ä���� c �ڿ� ���� ���ĺ��� ä��
	for (; i < 26; i++) {
		if ((isin(word, strlen(word), 'A' + k)) == 0)
			c[i] = 'A' + k++;
		else {
			i--;
			k++;
		}
	}

	// code�� distance��ŭ ���������� �̵��� temp �迭�� ����
	for (j = 0; j < distance; j++) {
		alpha = c[26 - distance];
		for (k = 26 - distance; k >= 0; k--) {
			after[k] = c[k - 1];
			if (k == 0)
				after[k] = alpha;
		}
	}
	after[26] = '\0';
}

void printCode(char* code) {
	printf("\n-------------------------------\n");
	printf("decoded:");
	for (int i = 0; i < 26; i++)
		printf("%c", 'A' + i);
	printf("\n");
	printf("encoded:%s\n", after);
	printf("-------------------------------\n\n");
}
int main(void)
{
	char code[26];//code[0]���� ��A'�� ��ȣȭ ���� ����
	int distance;
	char key[30];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);

	printf("Enter a word to use for encoding(�ҹ��ڷε� �ܾ��Է�):");
	scanf("%s", key);

	remove_duplicated_char(key);
	makeCode(after, distance, newWord); //makeCode(char c[], int distance, char* word)
	printCode(code);
}