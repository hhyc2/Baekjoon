#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
int arr[21][21];
int visit[21];
int result = 9999999999;
void find_min(int start, int count,int N)
{
	if (count == N / 2)
	{
		int A = 0;
		int B = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i] == 0 && visit[j] == 0)
					A = A + arr[i][j];
				else if (visit[i] == 1 && visit[j] == 1)
					B = B + arr[i][j];
			}
		}
		int value = abs(A - B);
		if (value < result)
			result = value;
		return;
	}
	for (int i = start; i < N; i++)
	{
		visit[i] = 1;
		find_min(start + 1, count + 1, N);
		visit[i] = 0;
	}
}
int main()
{
	int min = 0;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	}
	find_min(0,0,N);
	printf("%d", result);
}