#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void game()
{
	//雷的存放
	//布置雷的信息
	char mine[ROWS][COLS] = { 0 };
	//排查雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	initboard(mine, ROWS, COLS,'0');
	initboard(show, ROWS, COLS,'*');
	//打印棋盘
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//布置雷
	setmine(mine,ROW,COL);
	//displayboard(mine, ROW, COL);
	//扫雷
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
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
}


int main()
{
	test();

	return 0;
}
