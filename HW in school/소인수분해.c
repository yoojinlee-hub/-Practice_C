#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int j = 0;

void findPrime(int arr[], int n) {
	int i;
	while (n > 1) {
		for (i = 2; i < n; i++)
			if (n % i == 0)
				break;
		if (i == n) {
			arr[j] = i;
			j++;
		}
		n--;
	}
}
int main(void) {
	int n;
	int i;
	int arr[10000] = { 0 }; //2�� n������ �Ҽ��� ������ �迭

	printf("���ڸ� �Է����ּ���:");
	scanf("%d", &n);

	findPrime(arr, n);

	for (i = j-1; i > 0; i--) 
		if (n % arr[i] == 0) {
			printf("%d\n", arr[i]);
			n /= arr[i];
			i++;
		}
}