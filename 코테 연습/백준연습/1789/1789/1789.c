#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//���� �ٸ� N���� �ڿ����� ���� S��� �Ѵ�. S�� �� ��, �ڿ��� N�� �ִ��� ���ϱ�?
int main(void) {
    long long int S;
    long long int i, sum = 0;
    int N = 0;

    scanf("%lld", &S);

    for (i = 1; ; i++) {
        sum += i; //1���� ���س����� �ִ�
        N++;
        if (sum >= S) //=�� ����� ���̴� . ������ ?
            break;
    }
    
    printf("%d\n", N-1);

    return 0;
}