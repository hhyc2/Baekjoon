#include<queue>
#include<stdio.h>
#pragma warning(disable:4996)
using namespace std;
int N, K;
int visit[100001];
struct list
{
	int cnt = 0;
	int x;
};
queue <list> que;
void BFS()
{
	while (!que.empty())
	{
		list temp;
		temp = que.front();
		que.pop();
		if (temp.x == K)
		{
			printf("%d", temp.cnt);
			return;
		}
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				int nx = temp.x + 1;
				if (nx >= 0 && visit[nx] == 0 && nx <= 100000)
				{
					visit[nx] = 1;
					list A;
					A.x = nx;
					A.cnt = temp.cnt + 1;
					que.push(A);
				}

			}
			else if (i == 1)
			{
				int nx = temp.x - 1;
				if (nx >= 0 && visit[nx] == 0 && nx <= 100000)
				{
					visit[nx] = 1;
					list A;
					A.x = nx;
					A.cnt = temp.cnt + 1;
					que.push(A);
				}
			}
			else
			{
				int nx = 2 * temp.x;
				if (nx >= 0 && visit[nx] == 0 && nx <= 100000 )
				{
					visit[nx] = 1;
					list A;
					A.x = nx;
					A.cnt = temp.cnt + 1;
					que.push(A);
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &K);
	list temp;
	temp.x = N;
	que.push(temp);
	visit[N] = 1;
	BFS();
}
