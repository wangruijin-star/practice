#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void game()
{
	//�׵Ĵ��
	//�����׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//�Ų��׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	initboard(mine, ROWS, COLS,'0');
	initboard(show, ROWS, COLS,'*');
	//��ӡ����
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//������
	setmine(mine,ROW,COL);
	//displayboard(mine, ROW, COL);
	//ɨ��
	findmine(mine,show,ROW,COL);
}

void menu()
{
	printf("*****************************\n");
	printf("******1 play     0 exit******\n");
	printf("*****************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
}


int main()
{
	test();

	return 0;
}
