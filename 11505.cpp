#include<stdio.h>
#include<algorithm>
#include<math.h>
#pragma warning(disable:4996)
int N, M, K;
long long int arr[1 << 21];
long long int mul(int index, int start, int end, int left, int right)
{
	int mid = (start + end) / 2;
	if (left > end || right < start)
		return 1;
	if (start >= left && end <= right)
		return arr[index];
	return (mul(index * 2, start, mid, left, right) * mul(index * 2 + 1, mid + 1, end, left, right)) % 1000000007;
}
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	int size = pow(2, (int)log2(N-1) + 1);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[size + i]);
	for (int i = N; i < size; i++)
		arr[i + size] = 1;
	for (int i = size - 1; i > 0; i--)
		arr[i] = (arr[i * 2] * arr[i * 2 + 1]) % 1000000007;
	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)
		{
			int index = size + b - 1;
			arr[index] = c;
			for (int i = index / 2; i > 0; i = i / 2)
				arr[i] = (arr[i * 2] * arr[i * 2 + 1]) % 1000000007;
		}
		else if (a == 2)
		{
			long long int value = mul(1, 1, size, b, c);
			printf("%lld\n", value);
		}
	}
}