#include<stdio.h>
#pragma warning(disable:4996)
int N, M;
int arr[10];
void back(int start)
{
	if (start == M)
	{
		for (int i = 0; i < start; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++)
	{
		arr[start] = i + 1;
		back(start + 1);
	}
	return;
}
int main()
{
	scanf("%d %d", &N, &M);
	back(0);
}