#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int n);
int cnt = 0;

int main(void) {
	int num;

	scanf("%d", &num);
	
	printf("%d",sum(num));
	printf("\n");
}
int sum(int n) {
	int temp = n * 10 + 2;
	
	if (n == 0)
		return 0;
	else {
		printf("%d ", (cnt + 1) * 10 + 2);
		cnt++;
		if (cnt % n == 0)
			printf("\n");
		return temp + sum(n - 1);
	}
	
}