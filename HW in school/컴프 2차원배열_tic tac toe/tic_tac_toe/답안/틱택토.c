#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char board[3][3];
	int x, y, k, i, l, m, flag = 0;

	// ���带 �ʱ�ȭ�Ѵ�. 
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++) board[x][y] = ' ';

	// ����ڷκ��� ��ġ�� �޾Ƽ� ���忡 ǥ���Ѵ�. 
	for (k = 0; k < 9; k++) {
		if (k % 2 == 0) { // ��ǻ�� ����
			for (l = 0; l < 3; l++) {
				for (m = 0; m < 3; m++) {
					if (board[l][m] == ' ') {
						x = l;
						y = m;
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					printf("[��ǻ�� ����](x, y) ��ǥ: (%d, %d)\n", x, y);
					flag = 0;
					break;
				}
			}
		}
		else {
			printf("[�÷��̾� ����](x, y) ��ǥ: ");
			scanf("%d %d", &x, &y);
		}
		if (board[x][y] != ' ') {
			printf("��ġ�� �ٽ� �Է��ϼ���\n");
			k--;
		}
		else
			board[x][y] = (k % 2 == 0) ? 'X' : 'O';	// ������ ������ ���� 'X', 'O'�� ����

												// ���带 ȭ�鿡 �׸���. 
		for (i = 0; i < 3; i++) {
			printf("---|---|---\n");
			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		}
		printf("---|---|---\n");
	}

	return 0;
}