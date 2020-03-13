#include<stdio.h>
#pragma warning(disable:4996)
int N, M;
int arr[1001][1001];
int visit[1001];
int cnt=0;
void DFS(int start)
{
	visit[start] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 0 && (arr[i][start] == 1 || arr[start][i] == 1))
			DFS(i);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int first, second;
		scanf("%d %d", &first, &second);
		arr[first][second] = 1;
		arr[second][first] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 0)
		{
			visit[i]++;
			cnt++;
			DFS(i);
		}
	}
	printf("%d", cnt);
}