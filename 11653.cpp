#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int N;
	scanf("%d", &N);
	if (N == 1)
		printf("%d", 1);
	else
	{
		for (int i = 2; i <= N; i++)
		{
			while (1)
			{
				if (N % i == 0)
				{
					N = N / i;
					printf("%d\n", i);
				}
				else
					break;
			}
		}
	}
}