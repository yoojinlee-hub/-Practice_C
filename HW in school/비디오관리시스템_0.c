/***********
���������ý���0
************/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100
#define MAX_CHAR 100 // ���ڿ��� max ����
#include <stdio.h>
#include <string.h>


struct VideoInfo { // ��� ����: ���� �����ϰ� �ִ� Video ���� ����
	char title[MAX_CHAR];
	int qty; // ����
};


int main(void)
{
	int videoCount = 5;
	struct VideoInfo videoList[MAX_VIDEO] = { {"BeforeSunrise",1},{"BeforeSunset",3},{"BeforeMidnight",5},{"Casablanca",7},{"EdgeOfTomorrow",9}}; // ���� ����ó�� �ʱ�ȭ
	char title[MAX_CHAR];
	int qty; //����
	// �ʿ��� ���� �߰�
	int choice;
	int cnt;
	int i;

	printf("1(All Video ���), 2(����), 3(�˻�), 4(����): ");
	scanf("%d", &choice);

	while (choice != 4) {
		switch (choice) {
		case 1: // ���� Video���� ���
			printf("Video ����\t ����\n");
			printf("-----------------------\n");
			// ����
			for (i = 0; i < videoCount; i++)
				printf("%s  %d\n", videoList[i].title, videoList[i].qty);
			break;


		case 2: // Video ����
			cnt = 0;
			printf("Enter video ����: ");
			scanf("%s", title);
			printf("Enter video ����: ");
			scanf("%d", &qty);
			// ����
			for (i = 0; i < videoCount; i++)
				if (strcmp(videoList[i].title,title) == 0) {//������ ���� ��
					videoList[i].qty += qty;
					cnt++; //����
				}
			if (!cnt) { //����
				videoCount++;
				strcpy(videoList[i].title, title);//videoList[i + 1].title = title;
				videoList[i].qty += qty;
			}

			break;


		case 3: // title �� Video ã��
			cnt = 0;
			printf("Enter video ����: ");
			scanf("%s", title);
			//����
			for (i = 0; i < videoCount; i++) 
				if (strcmp(title, videoList[i].title) == 0) {//������ ���� ��
					if (videoList[i].qty >= 1)
						printf("�뿩 �����մϴ�\n");
					else
						printf("�뿩 �Ұ����մϴ�\n");
					cnt++; //����
				}
			if (!cnt)
					printf("�׷� ������ �����ϴ�\n");
			break;
		}
		printf("1(All Video ���), 2(����), 3(�˻�), 4(����): ");
		scanf("%d", &choice);
	}
}