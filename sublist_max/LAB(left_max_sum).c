//20191770������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int right_max_sum(int A[], int left, int right) {
	int i, sum = A[right], maxSum = A[right];

	for (i = right - 1; i >= left; i--) {
		sum += A[i];
		if (maxSum <= sum)
			maxSum = sum;
	}
	return maxSum;

}
int main() {
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int max;

	max = right_max_sum(A, 4, 6);// A[3], A[3]+A[4], A[3]+A[4]+A[5] �߿��� �ִ밪 ��, 3
	//max = right_max_sum(A, 0, 4);// A[3], A[3]+A[4] �߿��� �ִ밪 ��, 3
	//max = right_max_sum(A, 4, 7);// �ִ밪 -2
	printf("max value = %d\n", max);
}