#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
ù° �ٿ��� ī���� ���� N�� ��ǥ �� X�� �־�����, 
�ι�° �ٿ��� ī�忡 �����ִ� ���� �Է����� �־��� ��
X�� ���� �����鼭 X�� ���� �ʴ� 
ī�� ������ ���� ���ؼ� ����ϼ���.
*/
int main(void) {
	int size, target;
	int arr[100] = { 0 };
	int i, j, k;
	int sum = 0, newgap = 0, gap = 10000;

	scanf("%d %d", &size, &target);

	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	for(i=0;i<size;i++)
		for(j=i+1;j<size;j++)
			for (k = j + 1; k < size; k++) {
				sum = arr[i] + arr[j] + arr[k];
				newgap = target - sum;
				if (newgap <= gap && newgap > 0)
					gap = newgap;
			}
	printf("%d", target - gap);
}