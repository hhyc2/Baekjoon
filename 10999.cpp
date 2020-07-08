#include<stdio.h>
#pragma warning(disable:4996)
#include<math.h>
int N, M, K;
long long int seg[1 << 21];
long long int lazy[1 << 21];
void update_lazy(int index, int start, int end)
{
	if (lazy[index] == 0) // 값이 없으면 갱신 필요 x 
		return;
	seg[index] = seg[index] + ((end - start + 1) * lazy[index]);
	if (start != end)
	{
		lazy[index * 2] = lazy[index * 2] + lazy[index];
		lazy[index * 2 + 1] = lazy[index * 2 + 1] + lazy[index];
	}
	lazy[index] = 0;
}
void update_seg(int index,int start, int end, int left, int right, long long int value)
{
	update_lazy(index, start, end);
	int mid = (start + end) / 2;
	if (end < left || right < start)
		return;
	if (end <= right && left <= start)
	{
		int num = end - start + 1;
		seg[index] = seg[index] + (num * value);
		if (start != end) // 단말 노드가 아닐 때 하위 서브트리 2개에 값 넣어줌
		{
			lazy[index * 2] = lazy[index * 2] + value;
			lazy[index * 2 + 1] = lazy[index * 2 + 1] + value;
		}
		return;
	}
	update_seg(index * 2, start, mid, left, right, value);
	update_seg(index * 2 + 1, mid+1, end, left, right, value);
	seg[index] = seg[index * 2] + seg[index * 2 + 1];
}
long long int sum(int index, int start, int end, int left, int right)
{
	update_lazy(index, start, end);
	int mid = (start + end) / 2;
	if (end <= right && left <= start)
		return seg[index];
	if (end < left || right < start)
		return 0;
	return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	int size = pow(2, (int)log2(N - 1) + 1);
	for (int i = 0; i < N; i++)
		scanf("%lld", &seg[i + size]);
	for (int i = size - 1; i > 0; i--)
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	for (int i = 0; i < M + K; i++)
	{
		int a, b, c, d;
		scanf("%d ", &a);
		if (a == 1)
		{
			scanf("%d %d %d", &b, &c, &d);
			update_seg(1, 1, size, b, c, d);
		}
		else
		{
			scanf("%d %d", &b, &c);
			long long int value = sum(1, 1, size, b, c);
			printf("%lld\n", value);
		}
	}
}