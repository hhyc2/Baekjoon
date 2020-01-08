#include<stdio.h>
#pragma warning(disable:4996)
int arr[501][501];
int main()
{
	int N;
	int M;
	int B;
	int max=-1;
	int min=501;
	int time_result = 99999999;
	int block_height = 99999999;
	scanf("%d %d %d", &N, &M, &B);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (min > arr[i][j])
				min = arr[i][j];
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	for (int i = min; i <= max; i++)
	{
		int time = 0;
		int block = B;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				int height = arr[j][k]-i;
				if (height > 0)
				{
					time = time + height * 2;
					block = block + height;
				}
				else if (height < 0)
				{
					time = time - height;
					block = block + height;
				}
			}
		}
		if (block >=0)
		{
			if (time <= time_result)
			{
				time_result = time;
				block_height = i;
			}
		}
	}
	printf("%d %d", time_result, block_height);
}