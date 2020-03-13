#include<stdio.h>
#pragma warning(disable:4996)
int N, M, K;
int arr[102][102];
int visit[102][102];
int max = 0;
int value = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void DFS(int x, int y)
{
	visit[x][y] = 1;
	value++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || nx > N || ny<1 || ny > M)
			continue;
		if (visit[nx][ny] == 0 && arr[nx][ny] == 1)
			DFS(nx, ny);
	}
}
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == 0)
			{
				DFS(i, j);
				if (value > max)
				{
					max = value;
					value = 0;
				}
			}
		}
	}
	printf("%d", max);
}