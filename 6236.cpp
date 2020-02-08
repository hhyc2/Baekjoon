#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr[100001];
int value;
int N;
int M;
bool check(int mid)
{
	int num = 0;
	int sum = mid;
	for (int i = 0; i < N; i++)
	{
		if (mid < arr[i])
			return false;
		if (sum - arr[i] < 0)
		{
			sum = mid;
			num++;
		}
		sum = sum - arr[i];
	}
	return M > num;
}
void Search(int min, int max)
{
	if (min > max)
		return;
	else
	{
		int mid = (min + max) / 2;
		int cnt = 0;
		int money = mid;
		int flag = 0;
		check(mid);
		if (check(mid))
		{
			value = mid;
			Search(min, mid - 1);
		}
		else
		{
			Search(mid + 1, max);
		}	
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
	int min = 1;
	int max = sum;
	Search(min, max);
	printf("%d", value);
}
