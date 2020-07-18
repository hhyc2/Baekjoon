#include<stdio.h>
#pragma warning(disable:4996)
int n, m;
int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main()
{
	int value;
	scanf("%d:%d", &n, &m);
	if (n > m)
		value = gcd(n, m);
	else
		value = gcd(m, n);
	printf("%d:%d", n / value, m / value);

}