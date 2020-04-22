#include<stdio.h>
#pragma warning(disable:4996)
int N;
int arr[100001];
int visit[100001];
int finish[100001];
int cnt = 0;
void DFS(int n)
{
	visit[n]++;
	int temp = arr[n];
	if (visit[temp] == 0)
		DFS(temp);
	if (finish[temp] == 0)
	{
		int i = temp;
		while (1)
		{
			if (i == n)
				break;
			i = arr[i];
			cnt++;
		}
		cnt++;
	}
	finish[n]++;
}
void reset()
{
	for (int i = 1; i <= N; i++)
	{
		visit[i] = 0;
		finish[i] = 0;
	}
		
}
int main()
{
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	int Test;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d", &N);
		for (int j = 1; j <= N; j++)
			scanf("%d", &arr[j]);
		for (int j = 1; j <= N; j++)
		{
			if (visit[j] == 0)
				DFS(j);
		}
		printf("%d\n", N - cnt);
		cnt = 0;
		reset();
	}
}