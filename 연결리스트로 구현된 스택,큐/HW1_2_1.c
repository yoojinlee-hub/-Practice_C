//20191770 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;


// �ʱ�ȭ �Լ�
void init(LinkedStackType* s)
{
	s->top = NULL;
}

// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}

// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s) //�� ������ ���� ����
{
	return 0;
}

// ���� �Լ�
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		printf("�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}

// ���� �Լ�
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		printf("������ �������\n");
		return;
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

// ��ũ �Լ�
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		printf("������ �������\n");
		return;
	}
	else {
		return s->top->data;
	}
}

void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
//���� ��� �Լ�
void stack_print(LinkedStackType* s) {
	StackNode* temp = s->top;

	if (is_empty(s))
		printf("(empty)\n");
	else {
		while(temp!=NULL) {
			if (temp == s->top) 
				printf("%d <- top\n", s->top->data);
			else 
				printf("%d\n", temp->data);
			temp = temp->link;
		}
	}
	printf("--\n");
}

//main
void main() {
	LinkedStackType* s;

	init(&s);
	stack_print(&s);

	push(&s, 10);
	stack_print(&s);

	push(&s, 20);
	stack_print(&s);

	push(&s, 30);
	stack_print(&s);

	push(&s, 40);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	push(&s, 50);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
}