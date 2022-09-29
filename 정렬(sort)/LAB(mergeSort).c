#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int p, int q, int r)
{
	// ���ĵǾ� �ִ� �� �迭 A[p ... q]��
	// A[q+1 ... r]�� ���Ͽ�
	// ���ĵ� �ϳ��� �迭 A[p ... r]�� �����.

	int* sorted = (int*)malloc(sizeof(int) * r);
	int i = p, j = q + 1, t = 0;

	while (i <= q && j <= r) {
		if (A[i] <= A[j])
			sorted[t++] = A[i++];
		else
			sorted[t++] = A[j++];
	}

	while (i <= q)
		sorted[t++] = A[i++];
	while (j <= r)
		sorted[t++] = A[j++];

	t = 0;
	while (t <= r) {
		A[p + t] = sorted[t++];
	}
}
void mergeSort(int* A, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
void printList(int A[], int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main(void)
{
	int* A;
	int n, i;
	srand(time(NULL));

	scanf("%d", &n);
	A = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		A[i] = (int)(rand() % 99);

	mergeSort(A, 0, n - 1);
	printList(A, 0, n - 1);
}