//20191770 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL };
TreeNode m4 = { 25, NULL, &m7 };
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;


int get_node_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}
int get_leaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) {
			return 1;
		}
		else {
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
		}
	}
	return count;
}
//p290 Quiz 02
int get_nonleaf_count(TreeNode* t) {
	return get_node_count(t) - get_leaf_count(t);
}
int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL) {
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	return height;
}

int equal(TreeNode* t1, TreeNode* t2) {
	int ret = 0;
	if (t1 == NULL && t2 == NULL)
		ret = 1;
	else if (t1 != NULL && t2 != NULL && (t1->data == t2->data) && equal(t1->left, t2->left) && equal(t1->right, t2->right))
		ret = 1;

	return ret;
}
//p319 #16
// ��ܸ� ��� �� �ڽ��� �ϳ��� ����� ���� ��ȯ 
int get_oneleaf_count(TreeNode* root) {
	if (root != NULL) {
		if ((root->left != NULL) && (root->right == NULL)) 
			return 1 + get_oneleaf_count(root->left);
		else 
			if ((root->left == NULL) && (root->right != NULL)) 
				return 1 + get_oneleaf_count(root->right);
			else return get_oneleaf_count(root->left) + get_oneleaf_count(root->right); 
	} 
	return 0; 
} 
// ��ܸ� ��� �� �ڽ��� ���� ����� ���� ��ȯ 
int get_twoleaf_count(TreeNode* root) {
	if (root != NULL) {
		if (root->left != NULL && root->right != NULL)
			return 1 + get_twoleaf_count(root->left) + get_twoleaf_count(root->right);
		else 
			return get_twoleaf_count(root->left) + get_twoleaf_count(root->right); 
	}
	return 0; 
} 
//p319 #17
int get_max(TreeNode* node) {
	TreeNode* tmp = root;

	while (tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp->data;
}
int get_min(TreeNode* node) {
	TreeNode* tmp = root;

	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp->data;
}
void preorder(TreeNode* root) {
	if (root == NULL) return;

	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}
//p319 #20
TreeNode* node_increase(TreeNode* root) {
	if (root != NULL) {
		root->data += 1;
		if (root->left != NULL)
			node_increase(root->left);
		if (root->right != NULL)
			node_increase(root->right);
	}
	return root;
}

TreeNode* copy(TreeNode* p) {
	TreeNode* newNode = NULL; // ��Ʈ�� �� ���
	TreeNode* l;                     // left�� �� ���
	TreeNode* r;                    // right�� �� ���

	if (p != NULL) {                   // �Ű������� ���� Ʈ���� null�� �ƴ϶��
		l = copy(p->left);           // ����Լ��� �̿��Ͽ� left�� right�� ��������� �����ϴ� ��
		r = copy(p->right);
		newNode = (TreeNode*)malloc(sizeof(TreeNode));

		newNode->right = r;      // ��Ʈ�� right�� ������ ������ r�� ������
		newNode->left = l;        // ��Ʈ�� left�� ������ ������ l�� ������
		newNode->data = p->data;  // ��Ʈ�� ���������� Ʈ���������� �������� ������
	}
	return newNode;
}


int main(void)
{
	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;
	printf("��)\n");
	printf("Ʈ�� root �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root));
	printf("Ʈ�� root2 �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root2));

	printf("Ʈ�� root �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root2));
	printf("Ʈ�� root �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root2));
	printf("Ʈ�� root ���� ���� ū ���� %d.\n", get_max(root));
	printf("Ʈ�� root2 ���� ���� ū ���� %d.\n", get_max(root2));
	printf("Ʈ�� root ���� ���� ���� ���� %d.\n", get_min(root));
	printf("Ʈ�� root2 ���� ���� ���� ���� %d.\n", get_min(root2));
	printf("\n ��)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	printf("%s\n", equal(root, root) ? "����" : "�ٸ���");
	printf("%s\n", equal(root2, root2) ? "����" : "�ٸ���");
	printf("%s\n", equal(root, root2) ? "����" : "�ٸ���");
	printf("\n ��)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}