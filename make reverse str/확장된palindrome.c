
/*

������ �����ϰ� ��ҹ��ڸ� �������� �ʰ� �տ��� ������ �ڿ��� ������ ������ �ܾ ��

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int solution(char s[]) {
    // �ڵ� �ۼ�
    int i, size = 0, cnt = 0, j;
    char s1[50],s2[50];

    for (i = 0; ; i++) {
        if (s[i] == ' ') {
            cnt++;
            size++;
        }
        else if (s[i] != '\0')
            size++;
        else if (s[i] == '\0')
            break;
    }
    
    j = 0;
    for (i = 0; i < size; i++) {//�ҹ��ڷθ� ������ �Լ��� �ٲٱ�,
        if (s[i] != ' ') {
            if (isalpha(s[i]))
                s1[j] = tolower(s[i]);
            else
                s1[j] = s[i];
            j++;
        }
        else 
            continue;
    }
    s1[j] = '\0';
    for (i = 0; i < j; i++)//�Ųٷ� �� �Լ� �����
        s2[j - 1 - i] = s1[i];
    s2[j] = '\0';

    for (i = 0; i < j; i++) 
        if (s1[i] != s2[i])
            return 0;

    return 1;
}
int main(void) {
    char s[50];

    gets(s);
    printf("%d\n",solution(s));
}