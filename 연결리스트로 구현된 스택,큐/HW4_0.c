//20191770������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//������ ���� Ÿ�� ���� 
typedef TreeNode* element;

typedef struct {
	TreeNode* top;
} LinkedStackType;

//���⿡ ����� ���� ���α׷� �Լ��� �߰� 
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
TreeNode* insert_node(TreeNode* root, int key)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (root == NULL) return;
	// �׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (key < root->data)
		root->left = insert_node(root->left, key);
	else if (key > root->data)
		root->right = insert_node(root->right, key);
	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�.
	return root;
}


// ���� �Լ�
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		printf("������ �������\n");
		return;
	}
	else {
		TreeNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->right;
		free(temp);
		return temp;
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

//���� ��� �Լ�
void stack_print(LinkedStackType* s) {
	TreeNode* temp = s->top;

	if (is_empty(s))
		printf("(empty)\n");
	else {
		while (temp != NULL) {
			if (temp == s->top)
				printf("%d <- top\n", s->top->data);
			else
				printf("%d\n", temp->data);
			temp = temp->right;
		}
	}
	printf("--\n");
}

void inorder_iter(TreeNode* root)
{
	//���⿡ ����� ������ �̿��� �ݺ��� ��ȸ ���� �ڵ� �߰� 
	if (root != NULL) {
		inorder_iter(root->left);
		printf("[%d] ", root->data);
		inorder_iter(root->right);
	}
}

//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("���� ��ȸ=");
	inorder_iter(root);
	printf("\n");

	return 0;
}