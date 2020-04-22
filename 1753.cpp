#include<stdio.h>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
vector < pair <int, int> > vec[20001];
int V, E;
int start;
int value[20001];
int visit[20001];
priority_queue< pair< int, int>, vector < pair < int, int> >, greater< pair< int, int > > > que;
// 우선순위 큐 
int main()
{
	scanf("%d %d", &V, &E);
	scanf("%d", &start);
	for (int i = 0; i < E; i++)
	{
		int index; // start
		int f; // finish
		int c; // cost 
		scanf("%d %d %d", &index, &f, &c);
		vec[index].push_back({ f,c });
	}
	for (int i = 1; i <= V; i++)
		value[i] = 1e9;
	value[start] = 0;
	que.push({ 0, start }); // 첫번째는 가중치 , 두번째는 시작점
	while (!que.empty())
	{
		int cost = que.top().first;
		int index = que.top().second;
		que.pop();
		if (visit[index] == 0)
		{
			visit[index]++;
			value[index] = cost;
			for (int i = 0; i < vec[index].size(); i++)
			{
				if (visit[vec[index][i].first] == 0)
				{
					int nx_cost = cost;
					nx_cost = nx_cost + vec[index][i].second;
					int nx_f = vec[index][i].first;
					que.push({ nx_cost, nx_f });
				}
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (value[i] == 1e9)
			printf("INF\n");
		else
			printf("%d\n", value[i]);
	}
} 