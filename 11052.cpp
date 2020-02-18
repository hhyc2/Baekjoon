#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr[1002];
int DP[1002];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
			DP[i] = max(DP[i], arr[j] + DP[i - j]);
	}
	printf("%d", DP[N]);
}