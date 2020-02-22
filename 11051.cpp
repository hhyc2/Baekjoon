#include<stdio.h>
#pragma warning(disable:4996)
int DP[1001][1001];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == 0 || i == j)
				DP[i][j] = 1;
			else
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % 10007 ;
		}
	}
	printf("%d", DP[N][K]);
}