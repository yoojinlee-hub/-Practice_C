#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int win(char board[][3],int rowSize) {
    //(2)�������� �˻� 
    int i, j;
    int cnt = 0;
    //���� �˻�
    i = 0;
    while(i<3) {
        cnt = 0;
        for (j = 0; j < 2; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                if (board[i][j] == board[i][j + 1])
                    cnt++;
                if (cnt >= 2)
                    return 1;
            }
        }
        i++;
    }
    //���ΰ˻� - j�� ���� ���� �þ(�ι�° �ݺ�������)
    for (j = 0; j < 3; i++) {
        cnt = 0;
        for (i = 0; i < 2; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                if (board[i][j] == board[i + 1][j])
                    cnt++;
                if (cnt >= 2)
                    return 1;
                if (j > 3)
                    break;
            }
        }
    }
    //�밢�� �˻�
    if (board[0][0] != ' ' || board[1][1] == ' ' || board[2][2] != ' ') {
        if (board[0][0] == board[1][1])
            if (board[0][0] == board[2][2])
                return 1;
    }
    if (board[0][2] != ' ' || board[1][1] == ' ' || board[2][0] != ' ') {
        if (board[0][2] == board[1][1])
            if (board[0][2] == board[2][0])
                return 1;
    }

    //�⺻
    return 0;
}
int main(void)
{
    char board[3][3];
    int x, y, k, i, j;

    for (x = 0; x < 3; x++)
        for (y = 0; y < 3; y++) board[x][y] = ' ';

    for (k = 0; k < 9; k++) {
        //board[x][y] = (k % 2 == 0) ? 'X' : 'O'; //���ư��鼭 ��������
                                               //��ǻ�Ͱ� O - �������� 1�� ��
        if (k % 2 == 0) {
            printf("(x,y) ��ǥ(x,y<3):");
            scanf("%d%d", &x, &y);

            //(1)������ ���� ���� �ٽ� ���� �� ������ �ϴ� �ڵ�
            if (board[x][y] == 'X' || board[x][y] == 'O') {
                printf("�̹� ���� �ڸ��Դϴ�!\n");
                continue;
            }  
            else 
                board[x][y] == 'O';
            
        }
        //(3)��ǻ�Ͱ� �ڵ����� ���� �� �����ϴ� �˰���-����ִ� ù��° ��ǥ�� �ֱ�
        if (k % 2 == 1) {
            for(i=0;i<3;i++)
                for (j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] == 'O';
                        break;
                    }
                }
        }

        if (k > 0) {
            if (win(board, 3)) {
                printf("������ �������ϴ�");
                break;
            }
        }

        for (i = 0; i < 3; i++) {
            printf("---l---l---\n");
            printf(" %c l %c l %c \n", board[i][0], board[i][1], board[i][2]);
        }
        printf("---l---l---\n");

    }
    if (k == 9) {
        printf("���ºη� ������ �������ϴ�\n");
    }
    return 0;
}