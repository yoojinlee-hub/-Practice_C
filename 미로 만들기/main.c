// main.c

#include "header.h"



void MoveMaze();
int main(void)
{
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
        MoveMaze();
    }
}
