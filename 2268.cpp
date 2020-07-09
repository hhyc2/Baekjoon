#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
long long int seg[1 << 21];
int N;
int M;
long long int sum(int index, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return seg[index];
	long long int mid = (start + end) / 2;
	return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);

}
int main()
{
	scanf("%d %d", &N, &M);
	int size = pow(2, (int)log2(N) + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
		{
			if (b > c)
			{
				int temp;
				temp = c;
				c = b;
				b = temp;
			}
			printf("%lld\n", sum(1, 1, size, b, c));
		}
			
		if (a == 1)
		{
			int index = size + b - 1;
			seg[index] = c;
			for (index = index / 2; index > 0; index = index / 2)
				seg[index] = seg[index * 2] + seg[index * 2 + 1];
		}
	}
}