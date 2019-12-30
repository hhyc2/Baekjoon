#include<stdio.h>
#pragma warning(disable:4996)
int arr_N[101];
int arr_Q[1001];
int main()
{
	//freopen("1392.inp", "r", stdin);
	//freopen("1392.out", "w", stdout);
	int N;
	int Q;
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr_N[i]);
	for (int j = 0; j < Q; j++)
		scanf("%d", &arr_Q[j]);
	for (int j = 0; j < Q; j++)
	{
		int sum = -1;
		int temp = arr_Q[j];
		for (int i = 0; i < N; i++)
		{
			sum = sum + arr_N[i];
			if (sum >= temp)
			{
				printf("%d\n", i+1);
				break;
			}
		}
	}
}