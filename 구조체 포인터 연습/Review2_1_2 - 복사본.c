//�ڷᱸ�� 1�й� 
//�������� ��ǻ���а� 20191770 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int mid;
	int final;
}Score;
void printScore(Score* p) {
	printf("�߰���� ������ %d\n", p->mid);
	printf("�б⸻��� ������ %d\n", p->final);
}
Score* biggerScore(Score* p1, Score* p2) {
	int sum1 = 0, sum2 = 0;

	sum1 += p1->mid;
	sum1 += p1->final;

	sum2 += p2->mid;
	sum2 += p2->final;

	if (sum1 >= sum2) return p1;
	else return p2;
}
Score* totalScore(Score* p1, Score* p2) {
	int midSum = 0, finalSum = 0;
	Score* returnScore = (Score*)malloc(sizeof(Score));

	midSum = p1->mid + p2->mid;
	finalSum = p1->final + p2->final;

	returnScore->mid = midSum;
	returnScore->final = finalSum;

	return returnScore;
}
Score* createScore(int m, int f) {
	Score* returnScore = (Score*)malloc(sizeof(Score));
	returnScore->mid = m;
	returnScore->final = f;
	return returnScore;
}
int main(void) {
	Score s1, s2;
	Score* p3;

	s1.mid = 50; s1.final = 100;
	s2.mid = 70; s2.final = 70;

	printScore(&s1);
	printScore(&s2);

	printf("------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(&s1, &s2));

	printf("------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(&s1, &s2));

	printf("------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}