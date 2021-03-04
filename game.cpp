#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
			
	}
}

void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);

	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = easy_count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
		
	}
}


int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	int ret = 0;
	ret = mine[x - 1][y]
		+ mine[x - 1][y - 1] 
		+ mine[x][y - 1]
		+ mine[x + 1][y - 1] 
		+ mine[x + 1][y] 
		+ mine[x + 1][y + 1]
		+ mine[x][y + 1]
		+ mine[x - 1][y + 1] 
		- 8 * '0';
	return ret;
}


void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- easy_count)
	{
		
		printf("请输入坐标>:\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//输入正确
			if (mine[x][y] == '1')
			{
				printf("很遗憾你被炸死了\n");
				displayboard(mine, row, col);
				break;
			}
			else//不是雷，计算x，y周围雷的个数
			{
				int count=get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				displayboard(show, row, col);
				win++;
				
			}
			
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}

	}
	if (win < row * col - easy_count)
	{
		printf("恭喜你排雷成功\n");
	}
}
