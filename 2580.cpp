#include<stdio.h>
#pragma warning(disable:4996)
int map[10][10];
int index;
int flag = 0;
struct list
{
	int x;
	int y;
};
list arr[90];
bool check_rows(int x,int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (map[x][i] == num)
			return false;
	}
	return true;
}
bool check_cols(int y, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (map[i][y] == num)
			return false;
	}
	return true;
}
bool check_square(int x, int y, int num)
{
	for (int i = x / 3 * 3; i < x / 3 * 3 + 3; i++)
	{
		for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j++)
		{
			if (map[i][j] == num)
				return false;
		}
	}
	return true;
}
void make_sudoku(int cnt)
{
	if (cnt == index && flag==0)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}
		flag = 1;
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		int num = i;
		int x = arr[cnt].x;
		int y = arr[cnt].y;
		if (check_rows(x, num) && check_cols(y, num) && check_square(x, y, num))
		{
			map[x][y] = num;
			make_sudoku(cnt + 1);
			map[x][y] = 0;
		}
	}
}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
			{
				arr[index].x = i;
				arr[index].y = j;
				index++;
			}
		}
	}
	make_sudoku(0);
}