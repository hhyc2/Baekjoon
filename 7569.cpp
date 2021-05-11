#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
int M;
int N;
int H;
int arr[101][101][101];
int dx[6] = { 0,0, 1,-1,0,0 };
int dy[6] = { 0,0, 0,0,1,-1 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };
int value = 0;
struct list
{
	int x;
	int y;
	int z;
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
			int z = que.front().z;
			que.pop();
			for (int i = 0; i < 6; i++)
			{
				int temp_z = z + dz[i];
				int temp_x = x + dx[i];
				int temp_y = y + dy[i];
				if (temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < M && temp_z >= 0 && temp_z < H)
				{
					if (arr[temp_z][temp_x][temp_y] == 0)
					{
						list temp;
						temp.x = temp_x;
						temp.y = temp_y;
						temp.z = temp_z;
						que.push(temp);
						arr[temp_z][temp_x][temp_y] = 1;
					}
				}
			}
		}
		value++;
	}
}
bool find()
{
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[k][i][j] == 0)
					return false;
			}
		}
	}
	return 1;
}
int main()
{
	scanf("%d %d %d", &M, &N, &H);
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &arr[k][i][j]);
				if (arr[k][i][j] == 1)
				{
					list temp;
					temp.x = i;
					temp.y = j;
					temp.z = k;
					que.push(temp);
				}
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