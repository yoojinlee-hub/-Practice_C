#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
2���� �迭�� �־����� �� (i, j) ��ġ���� 
(x, y) ��ġ������ ����Ǿ� �ִ� ������ ���� ���ϴ� 
���α׷��� �ۼ��Ͻÿ�.
�迭�� (i, j) ��ġ�� i�� j���� ��Ÿ����.
*/

int main(void) {
	int N, M, K; //�����Ҵ� �̿�X
	int arr[300][300] = { 0 };
	int i, j, k;
	int minRows,minCols,maxRows,maxCols;
	int sum[10000] = { 0 };

	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);

	scanf("%d", &K);
	for (i = 0; i < K; i++) {
		scanf("%d", &minRows);
		scanf("%d", &minCols);
		scanf("%d", &maxRows);
		scanf("%d", &maxCols);

		for (j = minRows-1; j < maxRows; j++) //-1�� ����: 1,1 ó�� �������� ����� 0,0�̴�!
			for (k = minCols-1; k < maxCols; k++)
				sum[i] += arr[j][k];
	}
	
	for (i = 0; i < K; i++)
		printf("%d ", sum[i]);
	printf("\n");

}