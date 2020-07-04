#include<stdio.h>
#pragma warning(disable:4996)
int N, M;
int arr[10];
void back(int start, int index)
{
	if (start == M)
	{
		for (int i = 0; i < start; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = index; i < N; i++)
	{
		arr[start] = i + 1;
		back(start + 1, i);
	}
	return;
}
int main()
{
	scanf("%d %d", &N, &M);
	back(0, 0);
}
