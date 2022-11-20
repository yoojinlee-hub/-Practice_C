//20191770 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(TreeNode* root) { // ���� ��ȸ
	if (root) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		printf("[%d] ", root->key); // ��� �湮
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}

//Ž��(��ȯ)
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode* insert_node(TreeNode* root, int key)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (root == NULL) return new_node(key);
	// �׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (key < root->key)
		root->left = insert_node(root->left, key);
	else if (key > root->key)
		root->right = insert_node(root->right, key);
	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�.
	return root;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL) // �� ���� �ܸ� ��带 ã���� ������
		current = current->left;
	return current;
}
// ���� �Լ�
TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;
	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// �� ��° ���
		temp = min_value_node(root->right);
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->key = temp->key;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
int get_max(TreeNode* root) {
	TreeNode* tmp = root;

	while (tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp->key;
}
int get_min(TreeNode* root) {
	TreeNode* tmp = root;

	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp->key;
}
void preorder(TreeNode* root) {
	if (root == NULL) return;

	printf("%d ", root->key);
	preorder(root->left);
	preorder(root->right);
}
// Ʈ���� ���̸� ���ϴ� �Լ�
int get_height(TreeNode* root) {
	if (root != NULL) {
		return 1 + max(get_height(root->right), get_height(root->left)); 
	} 
	return 0; 
}
// ����� ������ ���ϴ� �Լ� 
int get_node_count(TreeNode* root) {
	if (root != NULL) {
		return 1 + get_node_count(root->left) + get_node_count(root->right); 
	} 
	return 0;
} 


int main(void) {
	TreeNode* root = NULL;
	char input = '0';

	while(1){
		int key = 0;
		
		printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,c<ount>,m<ax>,n<min>,q:");
		scanf("%c", &input);
		if (input == 'i') {
			printf("������ key�� �Է�:");
			scanf("%d", &key);
			root = insert_node(root, key);
		}
		if (input == 'd') {
			printf("������ key�� �Է�:");
			scanf("%d", &key);
			delete_node(root, key);
		}
		if (input == 's') {
			printf("Ž���� key�� �Է�:");
			scanf("%d", &key);
			TreeNode* a = search(root, key);
			if (a != NULL) printf("����\n");
			else printf("����\n");

		}
		if (input == 'p') {
			preorder(root);
			printf("\n");
		}	
		if (input == 'h') {
			printf("Ʈ���� ���̴� %d\n", get_height(root));
		}
		if (input == 'c') {
			printf("����� ������ %d\n", get_node_count(root));
		}
		if (input == 'm') {
			printf("���� ū ���� %d\n", get_max(root));
		}
		if (input == 'n') {
			printf("���� ���� ���� %d\n", get_min(root));
		}
		if (input == 'q')
			break;
		getchar();
	}

}