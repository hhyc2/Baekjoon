#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr[500001];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	int M;
	int value;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &value);
		printf("%d ", upper_bound(arr, arr + N, value) - lower_bound(arr, arr + N, value)); 
	}
}