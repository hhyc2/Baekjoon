#include<stdio.h>
#include<algorithm>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;
long long int arr[100001];
long long int N, M;
long long int value=LLONG_MAX;
int main()
{
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr + N);
	long long int min = 1;
	long long int max = 1000000000000000000LL;
	while (min <= max)
	{
		long long int mid = (min + max) / 2;
		long long int sum = 0;
		for (int i = 0; i < N; i++)
			sum = sum + (mid / arr[i]);
		if (sum >= M)
		{
			if (value > mid)
				value = mid;
			max = mid - 1;
		}
		else
			min = mid + 1;
	}
	printf("%lld", value);
}