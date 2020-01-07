#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
int arr[10];
int visit[10];
int temp[10];
int answer = -100000;
void find_min(int start, int N)
{
	if (start == N)
	{
		int value = 0;
		for (int i = 0; i < N - 1; i++)
			value = value + abs(temp[i] - temp[i + 1]);
		if (value > answer)
			answer = value;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			temp[start] = arr[i];
			find_min(start+1, N);
			visit[i] = 0;
		}
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	find_min(0, N);
	printf("%d", answer);
}