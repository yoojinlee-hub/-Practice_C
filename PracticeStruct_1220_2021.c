#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char name[20];
	int age;
	int grade;
	int math;
	int eng;
	int kor;
	int avg;
}Student;
int main(void) {
	Student s1;

	//�Է�
	printf("�̸� : ");
	scanf("%s", s1.name);
	printf("���� : ");
	scanf("%d", &s1.age);
	printf("�г� : ");
	scanf("%d", &s1.grade);
	printf("���� : ");
	scanf("%d", &s1.math);
	printf("���� : ");
	scanf("%d", &s1.eng);
	printf("���� : ");
	scanf("%d", &s1.kor);

	s1.avg = (s1.math + s1.kor + s1.eng) / 3;
	//���
	printf("[�л�]\n");
	printf("�̸� : %s\n", s1.name);
	printf("���� : %d\n", s1.age);
	printf("�г� : %d\n", s1.grade);
	printf("���� : %d\n", s1.math);
	printf("���� : %d\n", s1.eng);
	printf("���� : %d\n", s1.kor);
	printf("������� : %d\n", s1.avg);
}