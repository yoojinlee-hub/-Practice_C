/*****************
* HW(����ã��) ������ 20191770 ��ǻ���а� 3�г�
*********************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define X_VALUE 5 //2���� �迭�� ���� ��
#define Y_VALUE 5 //2���� �迭�� ���� ��

void readBombInfo(char grid[][Y_VALUE + 1])
{
	int i;
	// grid �� ���� ���� �Է�
	//printf("Input Grid\n");
	for (i = 0; i < X_VALUE; i++)
		scanf("%s", grid[i]); // ���ڿ� �������� ����!
}
void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*') {
				//���⿡ ������ ������ ���� numOfBombs�� �ִ� �ڵ� �ۼ�
				//���� ���ΰ� �ִ� �ڸ��� ������ �� ����
				for (int y = i - 1; y <= i + 1; y++) {
					for (int x = j - 1; x <= j + 1; x++) {
						if (i - 1 < 0 || j - 1 < 0 || i + 1 > Y_VALUE || j + 1 > Y_VALUE)
							continue;
						
							numOfBombs[y][x] += 1;
					}
				}
			}
}
void display_numOfBombs(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		printf("\n");
	}
}
int main(void)
{
	char grid[X_VALUE][Y_VALUE + 1]; //���ڿ��� ��� �������� NULL�� ���� �ϹǷ�
									// 5X5 �迭�� �ƴ� 5X6 �迭�� �Ǿ�� �Ѵ�.
	int numOfBombs[X_VALUE][Y_VALUE] = { 0 }; //������ ������ �ִ� ������ 5X5 �迭
	
	readBombInfo(grid);

	countBomb(grid, numOfBombs);

	display_numOfBombs(grid, numOfBombs);
}