// header.c
#include "header.h"
#include <conio.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224


void LoadMaze(char num)
{
    char path[20] = "./Maze";
    strcat(path, &num);
    strcat(path, ".txt");

    char str_tmp[50] = { 0, };
    FILE* f = fopen(path, "r");

    for (int i = 0; i < SIZE; i++)
    {
        fgets(str_tmp, 50, f);
        char* ptr = strtok(str_tmp, "\t");
        for (int j = 0; j < SIZE; j++)
        {
            maze[i][j] = *ptr;
            ptr = strtok(NULL, "\t");
        }
    }
    fclose(f);
}

void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void PrintMazeGame()
{

    for (int i = 0; i < SIZE; i++)
    {
        GotoXY(XP, YP + i);
        for (int j = 0; j < SIZE; j++)
        {
            if (maze[i][j] == '1')
                printf("��");
            else if (maze[i][j] == 'y')
                printf("��");
            else if (maze[i][j] == '0')
                printf("��");
            else
                printf("��");
        }
        puts("");
    }
}

void CursorView(char show)
{
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}
void MoveMaze()
{
    int nkey;

    if (_kbhit())
    {
        nkey = _getch();

        if (nkey == ARROW)
        {
            nkey = _getch();
            switch (nkey)
            {
            case UP:
                printf("�� ");
                break;

            case DOWN:
                printf("�Ʒ� ");
                break;

            case LEFT:
                printf("���� ");
                break;

            case RIGHT:
                printf("������ ");
                break;
            }
        }

    }

}
/*
void MoveMaze(���� �÷��̾��� ��ġ��ǥ (x), (y) ������ )
{
    int nkey;

    if (_kbhit())
    {
        nkey = _getch();

        if (nkey == ARROW)
        {
            nkey = _getch();
            switch (nkey)
            {
            case UP:
                if (������ ������ �ʾҴٸ�)
                                {
                                    �̷��� *(x), *(y)�� ��� ����;
                                    �̷��� *(x), *(y)-1�� �÷��̾�� ����;
                                  *(y)�� *(y)-1 �� ����
                                }
                                else if (������ ���������)
                                {
                                    �̷��� *(x), *(y)�� ��� ����;
                                    �̷��� *(x), *(y)-1�� �÷��̾�� ����;
                                    ���α׷� ����;
                                }
                break;

            case DOWN:
                if (�Ʒ����� ������ �ʾҴٸ�)
                                {
                                    �̷��� *(x), *(y)�� ��� ����;
                                    �̷��� *(x), *(y)+1�� �÷��̾�� ����;
                                  *(y)�� *(y)+1 �� ����
                                }
                                else if (�Ʒ����� ���������)
                                {
                                    �̷��� *(x), *(y)�� ��� ����;
                                    �̷��� *(x), *(y)-1�� �÷��̾�� ����;
                                    ���α׷� ����;
                                }
                break;

            case LEFT:
                                if (������ ������ �ʾҴٸ�)
                                {
                                    �̷��� *(x), *(y)�� ��� ����;
                                    �̷��� *(x)-1, *(y)�� �÷��̾�� ����;
                                  *(x)�� *(x)-1 �� ����
                                }
                                else if (������ ���������)
                                {
                                    �̷��� *(x), *(y)�� ��� ����;
                                    �̷��� *(x), *(y)-1�� �÷��̾�� ����;
                                    ���α׷� ����;
                                }
                break;

            case RIGHT:
                if (�������� ������ �ʾҴٸ�)
                                {
                                    �̷��� *(x), *(y)�� ��� ����;
                                    �̷��� *(x)+1, *(y)�� �÷��̾�� ����;
                                  *(x)�� *(x)+1 �� ����
                                }
                                else if (�������� ���������)
                                {
                                    �̷��� *(x), *(y)�� ��� ����;
                                    �̷��� *(x), *(y)-1�� �÷��̾�� ����;
                                    ���α׷� ����;
                                }
                break;
            }
        }

    }

}*/