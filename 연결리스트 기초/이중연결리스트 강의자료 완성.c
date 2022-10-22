//20191770 ������
#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct DListNode { // ���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�. 
void dinsert(DListNode *before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;

	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// ��� removed�� �����Ѵ�. 
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

//hw
void print_reverse_dlist(DListNode* head)
{
	DListNode* p;
	for (p = head->llink; p != head; p = p->llink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");

}
DListNode* search(DListNode* head, element data)
{
	DListNode* p;
	p = head;
	if (head == NULL) return;
	do {  //�� �ڱ��� ã��
		if (p->data == data)
			return p;
		p = p->llink; //�ڷ� �̵�
	} while (p != head);
	return p;
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");

	// �� �տ� ��带 ����
	dinsert(head, 10);
	print_dlist(head);
	dinsert(head, 20);
	print_dlist(head);
	dinsert(head, 30);
	print_dlist(head);

	//hw
	printf("�Ųٷ� ���\n");
	print_reverse_dlist(head);

	// �� �ڿ� ��带 �����Ϸ���?
	dinsert(head->llink, 99);
	print_dlist(head);

	printf("\n���� �ܰ�\n");
	// �� ���� ��带 ����
	ddelete(head, head->rlink);
	print_dlist(head);

	// �� ���� ��带 �����Ϸ���?
	ddelete(head, head->llink);
	print_dlist(head);

	
	free(head);
	return 0;
}