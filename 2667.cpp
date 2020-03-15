#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int N;
char arr[26][26];
int visit[26][26];
int cnt = 0;
int save[1000];
int value;
void DFS(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	if(visit[x][y] == 0)
	{
		visit[x][y]++;
		if (arr[x][y] == '1')
		{
			arr[x][y] = 0;
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
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", &arr[i]);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			value = 0;
			if (arr[i][j] == '1')
			{
				DFS(i, j);
				save[cnt] = value;
				cnt++;
			}
		}
	}
	sort(save, save + cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d\n", save[i]);
}