#include<stdio.h>
#pragma warning(disable:4996)
int arr[100001];
int N;
int M;
int value = 1e9;
void Search(int min, int max)
{
	if (min > max)
		return;
	int flag = 0;
	int mid = (min + max) / 2;
	int sum = 0;
	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > mid)
		{
			flag = 1;
			break;
		}
		sum = sum + arr[i];
		if (sum > mid)
		{
			sum = arr[i];
			cnt++;
		}
	}
	if (cnt > M || flag==1)
		Search(mid + 1, max);
	else if (cnt <= M)
	{
		if (mid < value)
			value = mid;
		Search(min, mid - 1);
	}
		
}
int main()
{
	scanf("%d %d", &N, &M);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		sum = sum + arr[i];
	}
	Search(1, sum);
	printf("%d", value);
}