#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
������ (5,7)��(5,9)�� ����, ���� ���ڰ� ���� ��츦 �������� ���� ������ �ڵ��Դϴ�.

�ϴ��� �ڵ� ������ �ϰ�, ���ĳ����ڽ��ϴ�.
*/
int N;// ȸ�� ����
int time[100][2] = { 0 };//(���۽ð�,����ð�)
int index[100][100] = { 0 };
int k = 0;
int findTime(int n,int arr[][2], int index[][100]) {
	int count = 1, end = 0;
	int i, j, l;

	l = 0;
	end = arr[n][1];
	index[k][l++] = n;
	for (i = 0; i < N; i++)
		if (n == i)continue;
		else {
			if (arr[i][0] > end) {
				end = arr[i][1]; count++;
				index[k][l++] = i;
			}
		}
	k++;
	return count;
}
int main(void) {
	int count = 0, end = 0, temp = 0;//count�� �� ����, end�� ������ �ð�
	int i, j;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < 2; j++)
			scanf("%d", &time[i][j]);

	count = findTime(0, time, index);
	for (i = 1; i < N; i++) {
		temp = findTime(i, time, index);
		if (count < temp) {
			count = temp;
			end = i;
		}
	}
	printf("%d#", count);
	for (i = 0; i < count; i++)
		printf("[%d,%d]", time[index[end][i]][0], time[index[end][i]][1]);
}