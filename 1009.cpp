#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int a;
	int b;
	int Test;
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d %d", &a, &b);
		long long int result = a;
		b = b % 4 + 4;
		for (int j = 2; j <= b; j++)
			result = (result * a) % 10;
		if (result == 0)
			printf("10\n");
		else
			printf("%lld\n", result);
	}
}