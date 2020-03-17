#include<stdio.h>
#pragma warning(disable:4996)
int N;
int max;
int value;
int max_value;
int arr[101][101];
int visit[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void DFS(int x, int y)
{
	if (visit[x][y] == 0)
	{
		visit[x][y]++;
		int nx;
		int ny;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx<0 || nx >=N || ny<0 || ny >= N)
				continue;
			else
			{
				if(arr[nx][ny] !=0 && visit[nx][ny] == 0)
				DFS(nx, ny);
			}
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}

	for (int n = 0; n <= max; n++)
	{
		for (int i = 0; i < N; i++) // 높이 표시 
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] <= n)
					arr[i][j] = 0;
			}
		}
		value = 0;
		for (int i = 0; i < N; i++) // DFS 돌리는 포문
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] != 0 && visit[i][j] == 0)
				{
					DFS(i, j);
					value++;
				}
			}
		}
		if (max_value < value)
			max_value = value;
		for (int i = 0; i < N; i++) // DFS 돌리는 포문
		{
			for (int j = 0; j < N; j++)
			{
				visit[i][j] = 0;
			}
		}
	}

	printf("%d", max_value);

}