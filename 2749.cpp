#include<stdio.h>
#pragma warning(disable:4996)
void divide(long long int N, long long int value[2][2])
{
	if (N == 1)
		return;
	else
	{
		divide(N / 2, value);
		if (N % 2 == 0)
		{
			long long int a = (value[0][0] * value[0][0] + value[0][1] * value[1][0]) % 1000000;
			long long int b = (value[0][0] * value[0][1] + value[0][1] * value[1][1]) % 1000000;
			long long int c = (value[1][0] * value[0][0] + value[1][1] * value[1][0]) % 1000000;
			long long int d = (value[1][0] * value[0][1] + value[1][1] * value[1][1]) % 1000000;
			value[0][0] = a;
			value[0][1] = b;
			value[1][0] = c;
			value[1][1] = d;
		}
		else
		{
			long long int a = (value[0][0] * value[0][0] + value[0][1] * value[1][0]) % 1000000;
			long long int b = (value[0][0] * value[0][1] + value[0][1] * value[1][1]) % 1000000;
			long long int c = (value[1][0] * value[0][0] + value[1][1] * value[1][0]) % 1000000;
			long long int d = (value[1][0] * value[0][1] + value[1][1] * value[1][1]) % 1000000;
			
			value[0][0] = a;
			value[0][1] = b;
			value[1][0] = c;
			value[1][1] = d;
			
			int fibo_first[2][2] = { {1,1},{1,0} };
			
			a = (value[0][0] * fibo_first[0][0] + value[0][1] * fibo_first[1][0]) % 1000000;
			b = (value[0][0] * fibo_first[0][1] + value[0][1] * fibo_first[1][1]) % 1000000;
			c = (value[1][0] * fibo_first[0][0] + value[1][1] * fibo_first[1][0]) % 1000000;
			d = (value[1][0] * fibo_first[0][1] + value[1][1] * fibo_first[1][1]) % 1000000;
			
			value[0][0] = a;
			value[0][1] = b;
			value[1][0] = c;
			value[1][1] = d;
		}
	}
}
int fibo(long long int N)
{
	long long int arr[2][2] = { {1,1},{1,0} };
	divide(N, arr);
	return arr[0][1];
}
int main()
{
	long long int N;
	scanf("%lld", &N);
	if (N == 0)
	{
		printf("0");
		return 0;
	}
	int value = fibo(N);
	printf("%d", value);
}