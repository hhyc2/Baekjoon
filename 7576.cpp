#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
int M;
int N;
int arr[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int value = 0;
struct list
{
	int x;
	int y;
	int cnt = 0;
};
queue <list> que;
void BFS()
{
	while (!que.empty())
	{
		int size = que.size();
		for (int j = 0; j < size; j++)
		{
			int x = que.front().x;
			int y = que.front().y;
			que.pop();
			for (int i = 0; i < 4; i++)
			{
				int temp_x = x + dx[i];
				int temp_y = y + dy[i];
				if (temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < M)
				{
					if (arr[temp_x][temp_y] == 0)
					{
						list temp;
						temp.x = temp_x;
						temp.y = temp_y;
						que.push(temp);
						arr[temp_x][temp_y] = 1;
					}
				}
			}
		}
		value++;
	}
}
bool find()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
				return false;
		}
	}
	return 1;
}
int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
			{
				list temp;
				temp.x = i;
				temp.y = j;
				que.push(temp);
			}
		}
	}
	if (que.empty())
	{
		printf("-1");
		return 0;
	}
	BFS();
	if (find())
		printf("%d", value - 1);
	else
		printf("-1");
}
