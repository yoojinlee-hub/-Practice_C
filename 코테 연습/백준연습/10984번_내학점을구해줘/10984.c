#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, j;
	int T, N, C, total;
	double G, GPA, scores;

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		total = 0;
		scores = 0;

		scanf("%d", &N);
		for (j = 1; j <= N; j++) {
			scanf("%d %lf", &C, &G);
			total += C;
			scores += (double)C * G;
		}
		GPA = scores / (double)total;
		printf("%d %.1f\n", total, GPA); //���⿡ \n�� �ȳ־ ��� Ʋ���ٰ� ���ؿ��� ������
	}
	return 0;
}