
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stringCompare(const char* s1, const char* s2)
{
	int count = 0;
	while (*s1 != '\0' || *s2 != '\0')
		if (*s1++ != *s2++) {
			if (*s1 > *s2)
				return -1; //���ľȵǴ� ���� ��������
			return 1; //���ĵ�
		}

	return 0; //������ 0 ����
}
void stringCat(char* s1, const char* s2)
{
	//�����ϴ� �Լ�(s1���ٰ�)
	int i, size = 0;

	while (*s1 != '\0') 
		s1++; //s1�� ũ�⸸ŭ �̵���
	while (*s2 != '\0')
		*s1++ = *s2++; //�̵� �� �� �������� s2�� �������
	*s1 = '\0';
}
void stringChange(char* s, char ch, char newCh)
{
	// s���ڿ� ���� ch ���ڸ� newCh�� �ٲٴ� �Լ�
	while (*s != '\0') {
		if (*s == ch) {
			*s = newCh;
			s++;
		}
		else
			s++;
	}

}
int main(void)
{
	char name1[20];
	char name2[20];

	printf("Enter the first name: ");
	scanf("%s", name1);
	printf("Enter the second name: ");
	scanf("%s", name2);

	if (stringCompare(name1, name2) == 0)
		printf("�ΰ��� �̸��� ����\n");
	else if (stringCompare(name1, name2) == 1)
		printf("�ΰ��� �̸��� �ٸ��� ���ĵǾ��ִ�\n");
	else
		printf("�ΰ��� �̸��� �ٸ��� ���ĵǾ������ʴ�\n");

	stringCat(name1, name2);
	printf("The concatenated name is %s\n", name1);

	stringChange(name1, 'u', 'x');
	printf("The changed name is %s\n", name1);
}