#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int N = 0; //�ܾ��� ����
	int i, j, k, l;
	int count = 0, size, cnt = 0;
	int nums[26]; //���ĺ��� ����
	char str[100], alpha[27];

	for (i = 0; i < 26; i++)
		alpha[i] = 'a' + i;
	alpha[26] = '\0';

	scanf("%d", &N);
	for (i = N; i > 0; i--) {
		scanf("%s", str);
		size = strlen(str);

		//�ʱ�ȭ
		for (j = 0; j < 26; j++)
			nums[j] = 0;
		cnt = 0;
		/*���� ���ĺ��� �� �� �ٽ� ������ �ȵ�
		for (j = 0; j < 26; j++)
			for (k = 0; k < size; k++)
				if (str[k] == alpha[j])
					nums[k]++;//���ĺ��� �ִ�
		for (j = 0; j < 26; j++)
			if (nums[j] > 1)
				cnt = 1;
		if (!cnt)
			count++;
		*/

		//���� ���ĺ��� �����ؼ� ������ ���� ��, ���Դ� ���ĺ��� �� �� �ٽ� ������ �ȵ�
		for (j = 0; j < 26; j++){
			for (k = 0; k < size; k++){
				if (str[k] == alpha[j]) {
					if (str[k] == str[k + 1]) 
						continue;
					nums[j]++;//���ĺ��� �ִ�
				}
			}
		}		
		for (l = 0; l < 26; l++)
			if (nums[l] > 1) 
				cnt += 1; //2�̻��̸� cnt���� 1
				
		if (!cnt) //cnt�� 0
			count++;
	}
	printf("%d", count);
}