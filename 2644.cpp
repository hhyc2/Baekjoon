#include<stdio.h>
#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int n;
int first;
int second;
int m;
vector <int> vec[101];
int visit[101];
int flag = 0;
void BFS(int start,int cnt)
{
	if (start == second)
	{
		printf("%d", cnt);
		flag = 1;
		return;
	}
	for (int i = 0; i < vec[start].size(); i++)
	{
		if (visit[vec[start][i]] == 0)
		{
			visit[vec[start][i]] = 1;
			BFS(vec[start][i], cnt + 1);
		}
	}
}
int main()
{
	scanf("%d", &n);	
	scanf("%d %d", &first, &second);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x;
		int y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	BFS(first,0);
	if (flag == 0)
		printf("-1");
}