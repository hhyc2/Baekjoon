#include<stdio.h>
#pragma warning(disable:4996)
int N, S;
int arr[100001];
int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int start = 0;
	int end = 0;
	int result = 1e9;
	int sum = arr[0];
	while (start<=end && end<N)
	{
		if (sum < S)
		{
			end++;
			sum = sum + arr[end];
		}
		else if (sum == S)
		{
			int index = end - start + 1;
			if (index < result)
				result = index;
			end++;
			sum = sum + arr[end];
		}
		else // sum >S
		{
			int index = end - start + 1;
			if (index < result)
				result = index;
			sum = sum - arr[start];
			start++;
		}
	}
	if (result == 1e9)
		printf("0");
	else
		printf("%d", result);
}