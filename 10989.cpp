#include<stdio.h>
#pragma warning(disable:4996)
int arr[10001];
int main()
{
	int N;
	int num;
	int count;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		arr[num]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] == 0)
			continue;
		else
		{
			count = arr[i];
			for (int j = 0; j < count; j++)
				printf("%d\n", i);
		}
	}
}