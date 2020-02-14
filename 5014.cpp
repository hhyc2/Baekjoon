#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
int F, S, G, U, D;
int flag = 0;
int visit[1000001];
struct list
{
	int cnt = 0;
	int floor;
};
queue <list> que;
void BFS()
{
	while (!que.empty())
	{
		list temp = que.front();
		que.pop();
		if (temp.floor == G)
		{
			flag = 1;
			printf("%d", temp.cnt);
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			int nx, ny;
			if (i == 0)
			{
				nx = temp.floor + U;
				if (nx <= F && visit[nx]==0)
				{
					visit[nx] = 1;
					list A;
					A.floor = nx;
					A.cnt = temp.cnt + 1;
					que.push(A);
				}
			}
			else if (i == 1)
			{
				nx = temp.floor - D;
				if (nx >= 0 && visit[nx] == 0)
				{
					visit[nx] = 1;
					list A;
					A.floor = nx;
					A.cnt = temp.cnt + 1;
					que.push(A);
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	list temp;
	temp.floor = S;
	que.push(temp);
	visit[S] = 1;
	// F 총 층수, S 지금 있는 층수, G 가야하는 충수, U 업, D 다운
	BFS();
	if (flag == 0)
		printf("use the stairs");
}
