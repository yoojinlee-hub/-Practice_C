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
    int answer = -1, num = 0;
    int onetoten[9], index[9] = { 0 };
    int i, j, k = 0;
    for (i = 0; i < 9; i++) 
        onetoten[i] = i + 1;
    
    for (i = 0; i < 9; i++) {
        answer = -1;
        if(numbers[i]>0){
            for (j = 0; j < 9; j++)
                if (numbers[i] == onetoten[j]) {
                    answer = 1;
                    break;
            } 
        }  
        if (answer != 1) index[k++] = i;
    }
    answer = 0;
    for (i = 0; i <= k; i++) {
        num = index[i];
        answer += onetoten[num];
    }
        
    return answer;
}
int main() {
    int arr[] = { 5,8,4,0,6,7,9 };

    printf("%d",solution(arr, 9));
}