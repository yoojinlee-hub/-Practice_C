#define _CRT_SECURE_NO_WARNINGS
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int XP = 40;
int YP = 5;

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
void MoveSquare()
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
                YP--;
                break;

            case DOWN:
                YP++;
                break;

            case LEFT:
                XP--;
                break;

            case RIGHT:
                XP++;
                break;
            }
        }
    }
}
int IsFinish(int x, int y) {
    if (x == 60)
        return 1;
    else
        return 0;
}
int main(void) {
    CursorView(0);
    int finish = 0;
    while (1) {
        //���߱� 
        int i = 0; 
        while (i < 30) { //i�� 30�� �Ѵ� �������� ���ڰŸ�
            GotoXY(60, i++);
            printf("|");
        }

        GotoXY(XP, YP);
        printf("0");
        if (_kbhit()) {
            if (IsFinish(XP, YP) == 1) {
                printf("|");
                finish = 1;
                break;
            }
            else
                MoveSquare();
            system("cls");
        }
    }
    if (finish) {
        system("cls");
        printf("���� ��� ���α׷��� �����ϴ�.");
    }
}