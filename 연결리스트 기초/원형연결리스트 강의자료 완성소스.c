//20191770 ������
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode { 
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) 
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d->����Ʈ�� ��", p->data); 
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data) 
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
		head = node; // (3)
	}
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* temp;
	if (head == NULL) {
		printf("����Ʈ�� ��� ������ ����\n");
			return NULL;
	}
	else if (head == head->link) {  //���� �ϳ�
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* p;
	ListNode* removed;
	p = head->link;

	if (head == NULL) {
		printf("����Ʈ�� ����־� ������ ����");
		return head;
	}
	
	while (p->link != head) {  //�� �ڱ��� ã��
		p = p->link; //�ڷ� �̵�
	}
	removed = head;
	p->link = removed->link;
	head = p;
	return head;
}
ListNode* search(ListNode* head, element data)
{
	ListNode* p;
	p = head;
	if (head == NULL) return;
	 do{  //�� �ڱ��� ã��
		if (p->data == data)
			return p;
		p = p->link; //�ڷ� �̵�
	}while (p != head);
	return p;
}
int get_size(ListNode* head)
{
	ListNode* p;
	p = head;
	int size = 0;
	do {  //�� �ڱ��� ã��
		size += 1;
		p = p->link; //�ڷ� �̵�
	} while (p != head);
	return size;
}

int main(void)
{
	ListNode* head = NULL;

	// list = 10->20->30->40


	head = insert_last(head, 20);
	print_list(head); //20
	head = insert_last(head, 30);
	print_list(head); //20->30
	head = insert_last(head, 40);
	print_list(head); //20->30->40
	head = insert_first(head, 10);
	print_list(head); //10->20->30->40
	head = delete_first(head);
	print_list(head); //20->30->40

	/*test*/
	head = delete_last(head);
	print_list(head); //20->30

	return 0;
}