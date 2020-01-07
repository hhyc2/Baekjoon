#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	//freopen("4539.inp", "r", stdin);
	//freopen("4539.out", "w", stdout);
	int N;
	int num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int j = 1;
		scanf("%d", &num);
		while (1)
		{
			if (num / (j * 10) != 0 && num > 10)
			{
				if (num % (j * 10) >= j * 5)
					num = num - num % (j * 10) + j * 10;
				else
					num = num - num % (j * 10);
				j = j * 10;
			}
			else
				break;
		}
		printf("%d\n", num);
	}
}