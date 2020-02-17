#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
int N, T, G;
int flag = 0;
int visit[200001];
struct list
{
	int num;
	int cnt = 0;
};
queue <list> que;
void BFS()
{
	while (!que.empty())
	{
		list temp;
		temp = que.front();
		que.pop();
		if (temp.cnt > T)
			break;
		if (temp.num == G)
		{
			printf("%d", temp.cnt);
			flag = 1;
			return;
		}
		int x = temp.num + 1;
		if (x <= 99999 && visit[x] == 0)
		{
			visit[x]=1;
			list A;
			A.num = x;
			A.cnt = temp.cnt + 1;
			que.push(A);
		}
		int y = 2 * temp.num;
		if (y <= 99999)
		{
			int value = 1;
			int B = y;
			while (B)
			{
				B = B / 10;
				value = value * 10;
			}
			value = value / 10;
			if (visit[y - value] == 0)
			{
				list A;
				A.num = y - value;
				visit[A.num]++;
				A.cnt = temp.cnt + 1;
				que.push(A);
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &N, &T, &G);
	list temp;
	temp.num = N;
	que.push(temp);
	visit[temp.num]++;
	BFS();
	if (flag == 0)
		printf("ANG");
}
