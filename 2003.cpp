#include<stdio.h>
#pragma warning(disable:4996)
int arr[10001];
int main()
{
	int N;
	int M;
	int count = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = i; j < N; j++)
		{
			sum = sum + arr[j];
			if (sum == M)
			{
				count++;
				break;
			}
			else if (sum > M)
				break;
		}
	}
	printf("%d", count);
}