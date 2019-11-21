#include<stdio.h>
#pragma warning(disable:4996)
int arr[101];
int main()
{
	int N;
	int M;
	int max = -1;
	int sum = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N ; j++)
		{
			for (int k = j + 1; k < N ; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= M)
				{
					if (max < sum)
						max = sum;
				}
			}
		}
	}
	printf("%d", max);

}