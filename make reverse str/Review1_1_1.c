//��ǻ���а� 4�г� 20191770 ������
//��ȯ palindrome ����� //�迭�߰�x
#include <stdio.h>
#include <string.h>

void reverse_string(char* str, int s, int e) {
	//��� ����ؾ��� -> ���� ������ �پ��� ��
	if (s == e / 2) printf("\n");
	else {
		
	}
}
int main() {
	char str[100];

	printf("Enter any string:");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;
}