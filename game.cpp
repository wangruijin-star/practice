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
	//��ӡ�к�
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
		
		printf("����������>:\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//������ȷ
			if (mine[x][y] == '1')
			{
				printf("���ź��㱻ը����\n");
				displayboard(mine, row, col);
				break;
			}
			else//�����ף�����x��y��Χ�׵ĸ���
			{
				int count=get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				displayboard(show, row, col);
				win++;
				
			}
			
		}
		else
		{
			printf("�����������������\n");
		}

	}
	if (win < row * col - easy_count)
	{
		printf("��ϲ�����׳ɹ�\n");
	}
}
