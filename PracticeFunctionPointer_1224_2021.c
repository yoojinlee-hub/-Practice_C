#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char signName(char s) {
	if (s == '+')
		return '+';
	else if (s == '-')
		return '-';
	else if (s == '*')
		return '*';
	else if (s == '/')
		return '/';
	else
		return s;
}
int answer(char s, int a, int b) {
	if (s == '+')
		return a + b;
	else if (s == '-')
		return a - b;
	else if (s == '*')
		return a * b;
	else if (s == '/') {
		if (b == 0)
			return -100000;
		else
			return a / b;
	}
	else
		return -100000;
}
int main(void) {
	int (*fp)(char);
	int (*p)(char, int, int);
	char sign, sign1;
	int ans = 0, a, b;

	//�����Է�
	printf("���� ����(+, -, *, / ) :");
	scanf("%c", &sign);

	fp = signName;
	sign1 = fp(sign);

	//�����Է�
	printf("a : ");
	scanf("%d", &a);
	printf("b : ");
	scanf("%d", &b);

	if (sign1 != 'w') {
		p = answer;
		ans = p(sign1, a, b);

		if (ans != -100000)
			printf("a %c b = %d\n", sign1, ans);
		else
			printf("��� �Ұ����� �����Դϴ�\n");
	}
	else
		printf("��� �Ұ����� �����Դϴ�\n");

	
}