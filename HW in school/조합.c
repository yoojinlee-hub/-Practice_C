#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(int n, int m, int picked[], int toPick)
{
	int smallest, lastIndex, i;
	if (toPick == 0) {// �� ���� ������ ���
		for (i = 0; i < m; i++)
			printf("%d ", picked[i]);
		printf("\n");
		return;
	}
	lastIndex = m - toPick - 1; //picked array���� �������� ä���� element�� index
	if (m == toPick) // ó�� ���� �Ÿ�
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;
	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(n, m, picked, toPick - 1);
	}
}
int main(void) {
	int picked[4];
	pick(7, 4, picked, 4);
}