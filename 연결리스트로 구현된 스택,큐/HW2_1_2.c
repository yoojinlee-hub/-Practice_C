//��ǻ���а� 20191770 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	char name[20];
}element;

typedef struct QueueNode { // ť�� ����� Ÿ��
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct { 
	QueueNode* front, * rear;
} LinkedQueueType;

// �ʱ�ȭ �Լ�
void init(LinkedQueueType* q)
{
	q->front = NULL;
	q->rear = NULL;
}

// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}

// ��ȭ ���� ���� �Լ�
int is_full(LinkedQueueType* q) // �׻� ����, ��ȭ�����϶��� ����
{
	return 0;
}

// ���� �Լ�
void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("�޸𸮸� �Ҵ��� �� �����ϴ�");
	else {
		temp->data = item; // ������ ����
		temp->link = NULL; // ��ũ �ʵ带 NULL
		if (is_empty(q)) { // ť�� �����̸�
			q->front = temp;
			q->rear = temp;
		}
		else { // ť�� ������ �ƴϸ�
			q->rear->link = temp; // ������ �߿�
			q->rear = temp;
		}
	}
}
// ���� �Լ�
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) // �������
		printf("ť�� ��� �����ϴ�");
	else {
		item = temp->data; // �����͸� ������.
		q->front = q->front->link; // front �� ������带 ����Ű���� �Ѵ�.
		if (q->front == NULL) // ���� ����
			q->rear = NULL;
		free(temp); // �����޸� ����
		return item; // ������ ��ȯ
	}
}

//�߰� �Լ� 1
int get_count(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->link;
	}
	return count;
}
//�߰��Լ� 2
void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	
	for (p = q->front; p != NULL; p = p->link) {
		printf("%s ", p->data.name);
	}
}

int main(void) {
	LinkedQueueType men;
	LinkedQueueType women;
	element e;

	int quit = 0;
	char input;
	char name[20];
	char gender;
	int numM, numF, is_full_M = 0, is_full_F = 0;

	init(&men);
	init(&women);

	printf("���� �ּ� ���α׷��Դϴ�.");
	while (quit != 1) {
		is_full_M = 0, is_full_F = 0;
		strcpy(e.name, "");

		printf("\ni<nsert,���Է�>,c<heck, ����� üũ>, q<uit>:");
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

				if (is_full(&men))
					is_full_M = 1;
				if (!is_full_M) {
					enqueue(&men, e);
					if (is_empty(&women))
						printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�");
					else
						printf("Ŀ���� ź���߽��ϴ�! %s�� %s", dequeue(&men).name, dequeue(&women).name); //dequeue�� return���� element�� �ִ� name ��ȯ
				}
				if (is_full_M && is_empty(&women))
					printf("���� ����ڰ� �����ϴ�.");
				if (is_full_M)
					printf("����ڰ� ��á���� ���ȸ�� �̿�");

			}
			else if (gender == 'f') {
				strcpy(e.name, name);

				if (is_full(&women))
					is_full_F = 1;
				if (!is_full_F) {
					enqueue(&women, e);
					if (is_empty(&men))
						printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�");
					else
						printf("Ŀ���� ź���߽��ϴ�! %s�� %s", dequeue(&women).name, dequeue(&men).name); //dequeue�� return���� element�� �ִ� name ��ȯ
				}
				if (is_full_F && is_empty(&men))
					printf("���� ����ڰ� �����ϴ�.");
				if (is_full_F)
					printf("����ڰ� ��á���� ���ȸ�� �̿�");

			}
			else
				printf("��Ÿ�Դϴ�");
			break;

		case 'c': //difficult!
			numM = get_count(&men);
			printf("���� ����� %d��:", numM);
			if (numM)
				print_queue(&men);

			numF = get_count(&women);
			printf("\n���� ����� %d��:", numF);
			if (numF)
				print_queue(&women);

			break;
		default:
			break;
		}
		getchar();//���ۺ���
	}
}