#include<stdio.h>
#pragma warning(disable:4996)
int arr[4000001];
int sosu[4000001];
int sosu_index = 0;
void make_sosu(int n)
{
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = 2; i * j <= n; j++)
			arr[i * j] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			sosu[sosu_index] = i;
			sosu_index++;
		}
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	make_sosu(num);
	int sum = 0;
	int count = 0;

	for (int i = 0; i < sosu_index; i++)
	{
		for (int j = i; j < sosu_index; j++)
		{
			if (sum < num)
				sum = sum + sosu[j];
			if (sum > num)
			{
				sum = 0;
				break;
			}
			if (sum == num)
			{
				count++;
				sum = 0;
				break;
			}
		}
	}
	printf("%d", count);
}