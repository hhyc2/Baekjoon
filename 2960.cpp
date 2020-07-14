#include<stdio.h>
#pragma warning(disable:4996)
int arr[1001];
int N, K;
int cnt = 0;
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; i * j <= N; j++)
		{
			if (arr[i * j] == 0)
			{
				arr[i * j]++;
				cnt++;
				if (cnt == K)
				{
					printf("%d", i * j);
					return 0;
				}
			}
		}
	}
}