//�������� �ڷᱸ��
//��ǻ���а� 20191770 ������
//HW1_1_2
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 3
#include <stdio.h>

//������ ���� Ÿ�� ����
typedef struct {
	int value;
	char name[20];
}element;

typedef struct {
	element data[MAX_STACK_SIZE];
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
	return s->top == MAX_STACK_SIZE - 1;
}
//�����Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		printf("���� ��ȭ ����\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}
//�����Լ�
element pop(StackType* s) {
	element temp;
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
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
				printf("[%d, %s] <- top\n", s->data[i].value, s->data[i].name);
			else
				printf("[%d, %s]\n", s->data[i].value, s->data[i].name);
		}
	}
	printf("--\n");
}
//main
void main() {
	StackType s;

	init(&s);
	stack_print(&s);

	element e1 = { 10,"ten" };
	push(&s, e1);
	stack_print(&s);
	
	element e2 = { 20, "twenty" };
	push(&s, e2);
	stack_print(&s);

	element e3 = { 30, "thirty" };
	push(&s, e3);
	stack_print(&s);

	element e4 = { 40, "forty" };
	push(&s, e4);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	element e5 = { 50, "fifty" };
	push(&s, e5);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
}