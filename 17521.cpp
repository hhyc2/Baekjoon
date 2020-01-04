#include<stdio.h>
#pragma warning(disable:4996)
int arr[16];
int main()
{
	int n;
	int w;
	int j;
	int temp=0;
	int save_min = 0;
	int save_max = 0;
	scanf("%d %d", &n, &w);
	long long int value = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	value = value + w;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[save_min])
		{
			save_max = i;
			for (j = i; j < n; j++)
			{
				if (arr[j] < arr[save_max])
				{
					temp = j;
					break;
				}
				else
					save_max = j;
			}
			value = (value / arr[save_min]) * arr[save_max] + value % arr[save_min];
			save_min = temp;
			i = j;
		}
		else
			save_min = i;
	}
	printf("%lld", value);
}