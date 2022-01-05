#define _CRT_SECURE_NO_WARNINGS
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224


#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CursorView(char show) //Ŀ�����ֱ�
{
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = show; //Ŀ���� ���⿩��
    ConsoleCursor.dwSize = 1; //Ŀ���� �β�
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}
int MoveMaze(int x,int y)
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
                GotoXY(x, y - 1);
                return UP;
                break;

            case DOWN:
                GotoXY(x, y + 1);
                return DOWN;
                break;

            case LEFT:
                GotoXY(x - 1, y);
                return LEFT;
                break;

            case RIGHT:
                GotoXY(x + 1, y);
                return RIGHT;
                break;
            }
        }

    }
    return 0;
}
int main(void) {
    int whereIs = 0;
    int XP = 10, YP = 10;
    int i = 0;
    CursorView(0);

    while (1) {
        if (i == 0)
            GotoXY(XP, YP);
        whereIs = MoveMaze(XP, YP);

        if (whereIs == UP) YP--;
        else if (whereIs == DOWN) YP++;
        else if (whereIs == LEFT) XP--;
        else if (whereIs == RIGHT) XP++;
        printf("��");

        Sleep(100);
        system("cls");
    }
}
/*
int main(void)
{

    int nkey;
    while (1)
    {
        if (_kbhit())
        {
            nkey = _getch();
            printf("%d\n", nkey);
        }
    }
}
// ������ : �Է��� Ű�� �ƽ�Ű �ڵ� ��
//�ƽ�Ű �ڵ� ���� 2����Ʈ ũ�⸦ ������ Ȯ��Ű
//_getch�Լ��� �ι� ȣ���ϸ� �ȴ�
*/