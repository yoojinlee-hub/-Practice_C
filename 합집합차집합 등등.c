#define _CRT_SECURE_NO_WARNINGS
#define MAX_SET_SIZE 10
#define HAVE_ELEMENT 1
#define DO_NOT_HAVE_ELEMENT 0
#include <stdio.h>

//set�� element�� ������ 1, ������ 0�� ��ȯ
int hasElement(int set[], int size, int element) {
	int i;
	for (i = 0; i < size; i++)
		if (set[i] == element)
			return HAVE_ELEMENT;
	return DO_NOT_HAVE_ELEMENT;
}
void printSet(int set[], int size) {
	int i;

	printf("{");
	for (i = 0; i < size; i++) {
		if (i == (size - 1))
			printf(" %d ", set[i]);
		else
			printf(" %d,", set[i]);
	}
	printf("}\n");

}
//set1�� set2�� ������ 1,�ٸ��� 0 ��ȯ
int isSetEqual(int set1[], int size1, int set2[], int size2) {
	int i, j;
	int count = 0;

	if (size1 != size2)
		return 0;
	else {
		for (i = 0; i < size1; i++)
			for (j = 0; j < size1; j++)
				if (set1[i] == set2[j])
					count++;
		if (count == size1)
			return 1;
		else
			return 0;
		/*
		* if(!hasElement(set2,size2,set1[i])
		* return 0;
		* 
		* return 1;
		*/
	}
}
//���Ұ� ���տ� �������� ������ �߰�, �̹� �����ϸ� redundant��� ����ϰ� ���� ���� ũ�⸦ ��ȯ
int addOneElement(int set[], int size, int element) {
	int i;
	int isit = 0;

	for (i = 0; i < size; i++) 
		if (set[i] == element) {
			printf("It is redundant. Please retry.\n");
			isit = 1;
			return size;
		}
	if (isit == 0) {
		set[size] = element;
		size++;
		return size;
	}
}
int main(void) {
	int setA[MAX_SET_SIZE] = { 1,2,3 };
	int setB[MAX_SET_SIZE] = { 3,2,4};
	int num;
	int sizeA = 3, sizeB = 3;

	printf("A: "); printSet(setA, sizeA);
	printf("B: "); printSet(setB, sizeB);

	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("���� A�� B�� ����\n");
	else
		printf("���� A�� B�� �ٸ���\n\n");

	printf("A�� 3�� �߰��ϸ�\n");
	sizeA = addOneElement(setA, sizeA, 3); 
	printf("���� A:"); printSet(setA, sizeA);

	printf("A�� 4�� �߰��ϸ�\n");
	sizeA = addOneElement(setA, sizeA, 4);
	printf("���� A:"); printSet(setA, sizeA);

	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("���� A�� B�� ����\n");
	else
		printf("���� A�� B�� �ٸ���\n");
}