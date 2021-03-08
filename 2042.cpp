#include<stdio.h>
#include<cmath>
#pragma warning (disable:4996)
long long int arr[1 << 21]; // 2의 21승 선언 shift
int N, M, K;
long long int sum(int itr, int start, int end, int left, long long int right)
{
	int mid = (start + end) / 2;
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return arr[itr];
	return sum(itr * 2, start, mid, left, right) + sum(itr * 2 + 1, mid + 1, end, left, right);
}
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	int size = pow(2, (int)log2(N - 1) + 1);
	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[size + i]);
	for (int i = size - 1; i > 0; i--)
		arr[i] = arr[i * 2] + arr[i * 2 + 1]; // 트리 생성
	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		long long int c;
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1)
		{
			int itr = size + b - 1;
			long long int diff = c - arr[itr];
			arr[itr] = c;
			for (itr = itr / 2; itr > 0; itr = itr / 2)
				arr[itr] = arr[itr] + diff;
		}
		else
		{
			long long int value = sum(1, 1, size, b, c);
			printf("%lld\n", value);
		}
	}
}
