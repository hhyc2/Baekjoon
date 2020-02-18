#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr[101];
int DP[100001];
int main()
{
	int n;
	int k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	DP[0] = 0;
	for (int j = 1; j <= k; j++)
	{
		DP[j] = 99999999;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = arr[i]; j <= k; j++)
		{
			DP[j] = min(DP[j], DP[j-arr[i]]+1);
			// 그 전 정보를 읽어온다
		}
	}
	if (DP[k] != 99999999)
		printf("%d", DP[k]);
	else
		printf("-1");
}




