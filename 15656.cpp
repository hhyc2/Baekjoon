#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int N, M;
int arr[10];
int value[10];
void back(int start)
{
	if (start == M)
	{
		for (int i = 0; i < start; i++)
			printf("%d ", value[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++)
	{
		value[start] = arr[i];
		back(start + 1);
	}
		
	return;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	back(0);
}
