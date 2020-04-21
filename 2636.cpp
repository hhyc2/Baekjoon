#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
struct list 
{
	int x;
	int y;
};
queue <list> que;
int map[101][101];
int visit[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, M;
int time;
int last_cheese;
int flag;
void reset() // ����� ��Ƽ� ��� ġ�� �κ��� ����� ��ȯ
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2)
				map[i][j] = 0;
		}
	}
}
void reset2() // �迭 �ʱ�ȭ 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 0;
		}
	}
}
void Find_cheese() // ġ���� ������ ã�� �Լ�
{
	flag = 0;
	int cheese = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
			{
				flag = 1;
				cheese++;
			}
		}
	}
	if (flag == 1)
		last_cheese = cheese;
}
void Find_Air() // 0�� ���� �� �ܺΰ��Ⱑ �ƴϱ� ������ ���⸦ ã���ִ� �Լ�
{
	reset2();
	list temp;
	temp.x = 0;
	temp.y = 0;
	que.push(temp);
	while (!que.empty())
	{
		list tmp;
		tmp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M )
			{
				if (visit[nx][ny] == 0 && map[nx][ny] != 1 )
				{
					visit[nx][ny]++;
					map[nx][ny] = -1;
					list A;
					A.x = nx;
					A.y = ny;
					que.push(A);
				}
			}
		}
	}
}
void Find_meltcheese() // ����� ��� ġ�� �κ��� ǥ���صδ� �Լ� 
{
	reset2();
	list temp;
	temp.x = 0;
	temp.y = 0;
	que.push(temp);
	while (!que.empty())
	{
		list tmp;
		tmp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && visit[nx][ny] == 0 )
			{
				if (map[nx][ny] == -1)
				{
					list A;
					A.x = nx;
					A.y = ny;
					que.push(A);
					visit[nx][ny]++;
				}
				if (map[tmp.x][tmp.y] == -1 && map[nx][ny] == 1)
				{
					map[nx][ny] = 2;
					visit[nx][ny] ++;
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	}
	while (1)
	{
		Find_cheese();
		if (flag == 0)
		{
			printf("%d\n", time);
			printf("%d\n", last_cheese);
			return 0;
		}
		Find_Air();
		Find_meltcheese();
		reset(); 
		time++;
	}
}