#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
long long int seg[1 << 21];
int n, q;
long long int sum(int index, int start, int end, int left, int right)
{
	int mid = (start + end) / 2;
	if (left <= start && end <= right)
		return seg[index];
	if (start > right || left > end)
		return 0;
	return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}
int main()
{
	scanf("%d %d", &n, &q);
	int size = pow(2, (int)log2(n) + 1);
	for (int i = 0; i < n; i++)
		scanf("%lld", &seg[size + i]);
	for (int i = size - 1; i > 0; i--)
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	for (int i = 0; i < q; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a>b)
		{
			int temp = b;
			b = a;
			a = temp;
		}
		printf("%lld\n", sum(1, 1, size, a, b));
		int index = size + c - 1;
		seg[index] = d;
		for (index = index / 2; index != 0; index = index / 2)
			seg[index] = seg[index * 2] + seg[index * 2 +1];
	}
}