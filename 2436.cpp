#include<stdio.h>
#pragma warning(disable:4996)
int make_gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}
int main()
{
	int gcd;
	int lcm;
	scanf("%d %d", &gcd, &lcm);
	int num = lcm / gcd;
	int a, b;
	for (int i = 1; i*i <= num; i++)
	{
		if (num % i == 0)
		{
			if (num / i > i)
			{
				if (make_gcd(num / i, i) == 1)
				{
					a = i;
					b = num / i;
				}
			}
			else
				if (make_gcd(i, num / i) == 1)
				{
					a = num / i;
					b = i;
				}
		}
	}
	printf("%d %d", a * gcd, b * gcd);
}