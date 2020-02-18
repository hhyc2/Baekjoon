#include<stdio.h>
#pragma warning(disable:4996)
long long int DP[1000001];
int main()
{
	DP[0] = 1;
	DP[1] = 1;
	int N;
	scanf("%d", &N);
	for (int i = 2; i <= N; i++)
		DP[i] = (DP[i - 1] + DP[i - 2])%15746;
	printf("%lld", DP[N]);
}