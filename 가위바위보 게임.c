#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int computerAnswer() {
	int random = rand() % 3 + 1; //1,2,3
	return random;
}
void whatIs(int n) {
	if (n == 1) printf("����");
	if (n == 2) printf("����");
	if (n == 3) printf("��");
}
int main(void) {
	int input, com = 0;

	printf("**************** ���� ���� �� ���� ****************\n");
	printf("1. ���� 2. ���� 3. �� \n�Է����ּ��� :");
	scanf("%d", &input);

	srand(time(NULL));
	com = computerAnswer();//1. ���� 2. ���� 3. ��

	printf("\n��ǻ��:");
	whatIs(com);
	printf("\n�����:");
	whatIs(input);

	if (com == input) printf("\n�����ϴ�.\n");
	else if (com == input + 1 || (input == 3 && com == 1)) printf("\n�����ϴ٤Ф�\n");
	else printf("\n�̰���ϴ�!\n");
}