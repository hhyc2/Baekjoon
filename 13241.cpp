#include<stdio.h>
#pragma warning(disable:4996)
long long int gcd(int A, int B)
{
	while (B != 0)
	{
		int temp = A % B;
		A = B;
		B = temp;
	}
	return A;
}
int main()
{
	long long int A;
	long long int B;
	scanf("%lld %lld", &A, &B);
	long long int value;
	if (A > B)
		value = gcd(A, B);
	else
		value = gcd(B, A);
	value = A * B / value;
	printf("%lld", value);
}