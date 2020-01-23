#include<stdio.h>
#pragma warning(disable:4996)
int visit[10];
int arr[10];
int N;
int M;
void find(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	for (int i=1;i<=N;i++)
	{
		if(visit[i] == 0)
		{
			arr[cnt] = i;
			visit[i] = 1;
			find(cnt + 1);
			visit[i] = 0;
		}
	}
	return;
}
int main()
{
	scanf("%d %d", &N, &M);
	find(0);
}