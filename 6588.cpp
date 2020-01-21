#include<stdio.h>
#pragma warning(disable:4996)
int arr[1000001];
void make_sosu()
{
	arr[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = 2; i * j <= 1000000; j++)
			arr[i * j] = 1;
	}
}
int main()
{
	int num;
	int flag = 0;
	make_sosu();
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
			return 0;
		else
		{
			for (int i = 2; i < num; i++)
			{
				if (arr[i] == 0 && arr[num - i] == 0)
				{
					printf("%d = %d + %d\n", num, i, num - i);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				printf("Goldbach's conjecture is wrong.\n");
		}
		flag = 0;
	}
}