#include<stdio.h>
#pragma warning(disable:4996)
int DP[100001];
int main()
{
	int num;
	scanf("%d", &num);
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	for (int i = 4; i <= num; i++)
	{
		DP[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			if (DP[i - j * j] + 1 < DP[i])
				DP[i] = DP[i - j * j] + 1;
		}
	}
	printf("%d", DP[num]);
}