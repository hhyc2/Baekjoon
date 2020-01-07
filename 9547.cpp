#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	int Test;
	int num;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		int visit[101] = { 0, };
		int max_index = 0;
		int max = 0;
		int second = 0;
		int second_index = 0;
		int arr[101][101] = { 0, };
		int check[101] = { 0, };
		int C;
		int V;
		scanf("%d %d", &C, &V);
		for (int j = 0; j < V; j++)
		{
			for (int k = 0; k < C; k++)
				scanf("%d", &arr[j][k]);
		}
		for (int j = 0; j < V; j++)
		{
			if (arr[j][0] != 0)
				check[arr[j][0]]++;
		}
		for (int j = 0; j <=C; j++)
		{
			if (check[j] > max)
			{
				max = check[j];
				max_index = j;
			}	
		}
		for (int j = 0; j <= C; j++)
		{
			if (check[j] > second && second <= max && max_index!=j)
			{
				second = check[j];
				second_index = j;
			}
		}
		if (max >= (double)V / 2)
			printf("%d %d\n", max_index , 1);
		else
		{
			for (int j = 1; j < C; j++)
			{
				for (int k = 0; k < V; k++)
				{
					if (arr[k][0] != max_index && arr[k][0] != second_index && visit[k]==0)
					{
						if (arr[k][j] == max_index)
						{
							max++;
							visit[k]++;
						}
						else if (arr[k][j] == second_index)
						{
							second++;
							visit[k]++;
						}
					}
				}
			}
			if (max >= (double)V / 2)
				printf("%d %d\n", max_index, 2);
			else if (second >= (double)V / 2)
				printf("%d %d\n", second_index, 2);
		}
	}
}