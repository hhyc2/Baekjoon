#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr[100001];
bool BinarySearch(int start, int end, int value)
{
	if (start > end)
		return false;
	int pivot = (start + end) / 2;
	if (arr[pivot] == value)
		return true;
	else
	{
		if (arr[pivot] > value)
			return BinarySearch(start, pivot - 1, value);
		else
			return BinarySearch(pivot + 1, end, value);
	}
}
int main()
{
	int N;
	int M;
	int num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num);
		if (BinarySearch(0, N, num))
			printf("1\n");
		else
			printf("0\n");
	}
}