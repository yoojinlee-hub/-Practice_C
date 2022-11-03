//20191770 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	int value;
	char name[20];
}element;

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
		int data_value = temp->data.value;
		char data_name[20] = "";
		strcpy(data_name, temp->data.name);
		element for_return;
		strcpy(for_return.name, data_name);
		for_return.value = data_value;
		s->top = s->top->link;
		free(temp);
		return for_return;
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
				printf("[%d, %s] <- top\n", s->top->data.value, s->top->data.name);
			else
				printf("[%d, %s]\n", temp->data.value, temp->data.name);
			temp = temp->link;
		}
	}
	printf("--\n");
}

//main
void main() {
	LinkedStackType s;

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

	pop(&s);
	stack_print(&s);
}