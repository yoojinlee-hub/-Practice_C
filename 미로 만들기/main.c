// main.c

#include "header.h"

int main(void)
{
    int row = 2, col = 1;
    char level;
    CursorView(0);

    GotoXY(XP, YP - 3);
    printf("�̷� ã�� ����\n");
    GotoXY(XP, YP - 2);
    printf("���̵��� �����ϼ���. (1, 2, 3) ");
    scanf("%c", &level);

    LoadMaze(level);

    while (1)
    {
        PrintMazeGame();
        MoveMaze(&row, &col);
    }
}
