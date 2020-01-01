#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	long long int N;
	scanf("%lld", &N);
	long long int num = 1;
	while (1)
	{
		if (num > N)
		{
			printf("0");
			break;
		}
		if (num == N)
		{
			printf("1");
			break;
		}
		num = num * 2;
	}
}