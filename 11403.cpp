#include<stdio.h>
#pragma warning(disable:4996)
int N;
int arr[101][101];
int visit[101];
void DFS(int x)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[x][i] == 1 && visit[i] == 0)
		{
			visit[i]++;
			DFS(i);
		}
	}
	return;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	}
	for (int i = 0; i < N; i++)
	{
		DFS(i);
		for (int j = 0; j < N; j++)
		{
			if (visit[j] == 1)
				arr[i][j] = 1;
			visit[j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}