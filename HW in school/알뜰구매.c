/*************************
20191770 ������ ��ǻ���а� 3�г�
https://enter.tistory.com/68 �̰ź�����
!!!!!!!!!!!!�����ʿ�!!!!!!!!!!!!
*************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

int main(void) {
	int money, bread = 0, cookie = 0, coke = 0;

	printf("Enter �ݾ�:");
	scanf("%d", &money);
	
	for(bread=500;bread<money;bread+=500)
	for(cookie=700;cookie<money;cookie+=700)
	for(coke=400;coke<money;coke+=400)

		if (bread + cookie + coke == money) {
			printf("��: %d ��Ű: %d �ݶ�: %d\n", bread / 500, cookie / 700, coke / 400);
		}
		else
			continue;

	return 0;
}