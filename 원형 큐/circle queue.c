//20191770 ��ǻ���а� ������
// HW2_1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_QUEUE_SIZE 3

typedef struct {
	char name[20];
}element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

// �ʱ�ȭ�Լ�
void init(QueueType* q) {
	q->front = 0; q->rear = 0;
}

//������� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return (q->front) % MAX_QUEUE_SIZE == (q->rear + 1) % MAX_QUEUE_SIZE;
}

//���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

//���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

//������ �Լ�
element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

//�߰� �Լ� 1
int get_count(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return (q->rear % MAX_QUEUE_SIZE) - (q->front % MAX_QUEUE_SIZE);
}
//�߰��Լ� 2
void print_queue(QueueType* q) {
	int index = q->front;
	int rear = q->rear;
	char content[20] = "";

	while (1) {
		strcpy(content, q->queue[(index + 1) % MAX_QUEUE_SIZE].name);//peek sudo
		printf("%s ", content); 
		index = (index + 1) % MAX_QUEUE_SIZE; //dequeue sudo
		if (index == rear) { //is_empty sudo
			printf("\n");
			break;
		}
	}
}

int main(void) {
	QueueType men;
	QueueType women;
	element e;

	int quit = 0;
	char input;
	char name[20];
	char gender;
	int numM, numF;

	init(&men);
	init(&women);

	printf("���� �ּ� ���α׷��Դϴ�.\n");
	while (quit != 1) {
		strcpy(e.name, "");

		printf("i<nsert,���Է�>,c<heck, ����� üũ>, q<uit>:");
		scanf("%c", &input);

		switch (input)
		{
		case 'q':
			quit = 1;
			break;
		case 'i':
			printf("�̸��� �Է�:");
			scanf("%s", &name);

			getchar();//���ۺ���

			printf("������ �Է�<m of f>:");
			scanf("%c", &gender);

			if (gender == 'm') {
				strcpy(e.name, name);
				enqueue(&men, e);
				if (is_empty(&women))
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�\n");
				else {
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", dequeue(&men).name, dequeue(&women).name); //dequeue�� return���� element�� �ִ� name ��ȯ
				}
			}
			else if (gender == 'f') {
				strcpy(e.name, name);
				enqueue(&women, e);
				if (is_empty(&men))
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�\n");
				else {
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", dequeue(&women).name, dequeue(&men).name); //dequeue�� return���� element�� �ִ� name ��ȯ
				}
			}
			else
				printf("��Ÿ�Դϴ�");
			break;

		case 'c': //difficult!
			numM = (men.rear % MAX_QUEUE_SIZE) - (men.front % MAX_QUEUE_SIZE);
			
			printf("���� ����� %d��:", numM);
			if (numM)
				print_queue(&men);
			else
				printf("\n");

			numF = (women.rear % MAX_QUEUE_SIZE) - (women.front % MAX_QUEUE_SIZE);
			
			printf("���� ����� %d��:", numF);
			if (numF)
				print_queue(&women);
			else
				printf("\n");
			break;
		default:
			break;
		}
	}
}