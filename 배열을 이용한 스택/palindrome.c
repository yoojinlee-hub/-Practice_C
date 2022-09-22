//�������� �ڷᱸ��
//��ǻ���а� 20191770 ������
//HW1_1_1
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 3
#define MAX_STRING 30
#include <stdio.h>
#include <string.h>


//������ ���� Ÿ�� ����
typedef char element;

typedef struct {
	element data[MAX_STRING];
	int top;
}StackType;

//���� �ʱ�ȭ �Լ�
void init(StackType* s) {
	s->top = -1;
}
//���� ���� �����Լ�
int is_empty(StackType* s) {
	return s->top == -1;
}
//��ȭ ���� �����Լ�
int is_full(StackType* s) {
	return (s->top == MAX_STRING - 1);
}
//�����Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		printf("���� ��ȭ ����\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
		return;
	}
}
//�����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
//��ũ�Լ�
element peek(StackType* s) {
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
//���� ��� �Լ�
void stack_print(StackType* s) {
	int i;

	if (is_empty(s))
		printf("<empty>\n");
	else {
		for (i = s->top; i >= 0; i--) {
			if (i == s->top)
				printf("%d <- top\n", s->data[i]);
			else
				printf("%d\n", s->data[i]);
		}
	}
	printf("--\n");
}


int palindrome(char str[]) {
	StackType s;

	//�ʿ��� ������ ����
	int i, j = 0;
	int len = strlen(str);

	//������ �ʱ�ȭ�϶�
	init(&s);

	//str�� ���ڵ��� ���ÿ� �ִ´�
	for (i = 0; i < len; i++)
		push(&s, str[i]);
	s.data[i] = '\0';

	//���ÿ��� �ϳ��� ���鼭 str�� ���ڵ�� ���ʷ� ��
	for (j = 0; j < len; j++)
		if (pop(&s) != str[j])
			return 0;
	return 1;
}


//main
void main() {
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome �Դϴ�.\n");
	else
		printf("palindrome �� �ƴմϴ�.\n");
}