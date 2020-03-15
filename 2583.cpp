#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int M, N, K;
int arr[101][101];
int visit[101][101];
int save[1001];
int cnt;
int value = 0;
void DFS(int x, int y)
{
	if (x<0 || y<0 || x >= M || y>=N )
		return;
	if (visit[x][y] == 0)
	{
		visit[x][y] = 1;
		if (arr[x][y] == 0)
		{
			arr[x][y] = 1;
			value++;
			DFS(x + 1, y);
			DFS(x - 1, y);
			DFS(x, y + 1);
			DFS(x, y - 1);
		}
	}
	return; 
}
int main()
{
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++)
	{
		int first_x;
		int first_y;
		int second_x;
		int second_y;
		scanf("%d %d %d %d", &first_x, &first_y, &second_x, &second_y);
		for (int j = first_y; j <second_y ; j++)
		{
			for (int k = first_x ; k < second_x ; k++)
				arr[j][k] = 1;
		}
	}
	for (int j = 0; j < M; j++)
	{
		for (int k = 0; k < N; k++)
		{
			value = 0;
			if (arr[j][k] == 0)
			{
				DFS(j, k);
				save[cnt] = value;
				cnt++;
			}
		}
	}
	sort(save, save + cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d ", save[i]);
}