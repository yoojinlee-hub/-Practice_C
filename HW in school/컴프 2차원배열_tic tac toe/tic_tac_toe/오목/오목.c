/*https://devyul.tistory.com/entry/C-3X3-%EA%B2%8C%EC%9E%84%ED%8C%90%EC%9D%98-Tic-Tac-Toe*/
#include <stdio.h>
#define WIDTH 3
#define HEIGHT 3

int winCheck(int sum)
{
	if (sum == 3)
	{
		printf("Player X wins!\n");
		return 1;
	}
	else if (sum == -3)
	{
		printf("Player O wins!\n");
		return 1;
	}

	return 0; //�ƹ��� ���̱�
}

int win(int b[][HEIGHT])
{
	int i, j;
	int sum;
	// ���η� ������ üũ
	for (i = 0; i < WIDTH; i++)
	{
		sum = 0; //���� üũ�ؾ��ϹǷ� �Ź� �ʱ�ȭ
		for (j = 0; j < HEIGHT; j++)
			sum += b[i][j];

		if (winCheck(sum)) return 1;
	}

	// ���η� ������ üũ
	for (j = 0; j < HEIGHT; j++)
	{
		sum = 0;
		for (i = 0; i < WIDTH; i++)
			sum += b[i][j];
		if (winCheck(sum)) return 1;
	}
	// �밢�� üũ
	sum = 0;
	for (i = 0; i < WIDTH; i++)
	{
		sum += b[i][i];
	}
	if (winCheck(sum)) return 1;

	// ���밢�� üũ
	sum = 0;
	for (i = 0; i < WIDTH; i++)
	{
		sum += b[i][WIDTH - 1 - i];
	}
	if (winCheck(sum)) return 1;

	return 0;
}

void display(int b[][HEIGHT])
{
	char ch;
	int i, j;

	printf("    0 1 2\n");
	printf("   ------\n");
	for (i = 0; i < WIDTH; i++)
	{
		printf("%d |", i);
		for (j = 0; j < HEIGHT; j++)
		{
			if (b[i][j] == 1)
				ch = 'X';
			else if (b[i][j] == -1)
				ch = 'O';
			else
				ch = ' ';
			printf(" %c", ch);
		}
		printf("\n");
	}
}

int main(void)
{
	int board[3][3];
	char turn = 'X'; //ó�� turn�� X�� ����

	int r, c;
	int i, j;
	int count;
	int lose;

	for (i = 0; i < WIDTH; i++)
		for (j = 0; j < HEIGHT; j++)
			board[i][j] = 0;

	count = 0;
	display(board);

	do
	{
		printf("Player %c(�� ��):", turn);
		scanf("%d %d", &r, &c);
		printf("\n");

		if (board[r][c]) //�̹� ä���������� �ٽ� �Է� ������Ʈ ����
			continue;		//�ڵ� �����κ����� ���ư�

		count++; //�ɺ��� �Էµ� Ƚ�� ����

		if (turn == 'X') {

			board[r][c] = 1;
			turn = 'O'; //���� �ٲ���
		}
		else {
			board[r][c] = -1;
			turn = 'X';
		}
		display(board);

	} while ((lose = !win(board)) && count < 9); //count�� 9 �̸��̸� 3x3 �� �������� �� ä������ ���� ����

	if (lose && count == 9)
		printf("Nobody wins!\n");
}