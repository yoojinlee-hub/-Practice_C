#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
0���� 9������ ���� �� �Ϻΰ� ����ִ� ���� 
�迭 numbers�� �Ű������� �־����ϴ�. 
numbers���� ã�� �� ���� 0���� 9������ ���ڸ� ��� ã�� 
���� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/
// numbers_len�� �迭 numbers�� �����Դϴ�.
int solution(int numbers[], size_t numbers_len) {
    int sum = 0, total = 45;
    int i;
    for (i = 0; i < numbers_len; i++)sum += numbers[i];
    sum = total - sum;
    return sum;
}
int main() {
    int arr[] = { 5,8,4,0,6,7,9 };

    printf("%d",solution(arr, 6));
}