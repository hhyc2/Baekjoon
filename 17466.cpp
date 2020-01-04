#include<stdio.h>
#pragma warning(disable:4996)
long long int fact(long long int N, long long int P)
{
	long long int result = 1;
	for (long long int i = 1; i <= N; i++)
	{
		result = result * i;
		result = result % P;
	}
	return result;
}
int main()
{
	long long int N;
	long long int P;
	scanf("%lld %lld", &N, &P);
	printf("%lld", fact(N, P));

}