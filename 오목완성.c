/***********
����ϼ� 20191770 ������ ��ǻ���а� 3�г�
************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 10

void display(char b[][BOARD_SIZE])
{
    char ch;
    int i, j;
    printf("     ");
    for (i = 0; i < BOARD_SIZE; i++)
        printf("%2d", i);
    printf("\n     ---------------------\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%3d |", i);
        for (j = 0; j < BOARD_SIZE; j++)
            printf(" %c", b[i][j]);
        printf("\n");
    }
}

int winCheck(char b[][BOARD_SIZE], int r, int c)
{
    int i;
    char player = b[r][c];
    int cnt = 0;

    //����üũ
    for (i = c - 1; i < BOARD_SIZE; i++)//����
        if (b[r][i] != player)
            break;
        else
            cnt++;
    for (i = c + 1; i < BOARD_SIZE; i++)//������
        if (b[r][i] != player)
            break;
        else
            cnt++;
    if (cnt == 5)
        return 1;
    //����üũ
    cnt = 0;
    for (i = r - 1; i < BOARD_SIZE; i++)//��
        if (b[i][c] != player)
            break;
        else
            cnt++;
    for (i = r + 1; i < BOARD_SIZE; i++)//�Ʒ�
        if (b[i][c] != player)
            break;
        else
            cnt++;
    if (cnt == 5)
        return 1;
    // \ �밢�� üũ
    cnt = 0;
    for (i = 0; i < BOARD_SIZE; i++)//��
        if (b[r-i][c-i] != player)
            break;
        else
            cnt++;
    for (i = 0; i < BOARD_SIZE; i++)//�Ʒ�
        if (b[r+i][c+i] != player)
            break;
        else
            cnt++;
    if (cnt == 6)
        return 1;
    // / �밢�� üũ
    cnt = 0;
    for (i = 0; i < BOARD_SIZE; i++)//��
        if (b[r - i][c + i] != player)
            break;
        else
            cnt++;
    for (i = 0; i < BOARD_SIZE; i++)//�Ʒ�
        if (b[r + i][c - i] != player)
            break;
        else
            cnt++;
    if (cnt == 6)
        return 1;
    return 0; // i�̱��� �ʾ��� ��
}

void main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
    int r, c;
    int i, j;
    int count;

    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            board[i][j] = ' ';

    count = 1;
    display(board);

    do
    {
        turn = 'X'; // �ٽ� �ʱ�ȭ �ʿ�

        if (count % 2 != 1)
            turn = 'O';

        printf("Player %c(�� ��):", turn);
        scanf("%d %d", &r, &c);

        if (board[r][c] == ' ') {
            board[r][c] = turn;
            display(board);

            if (winCheck(board, r, c) == 1) {
                printf("Player %c wins!\n", turn);
                break;
            }

            count++;
        }
    } while (count <= BOARD_SIZE * BOARD_SIZE);
}