#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, E;
int v1, v2;
struct list
{
	int end;
	int cost;
};
vector<list> vec[801];
void findRoad(int start)
{
	int visit[801];
	int dist[801];
	visit[start] = 1;
	queue<list> que;
	que.push({ start,0 });
	while (!que.empty())
	{
		list temp = que.front();
		que.pop();
		for (int i = 0; i < vec[temp.end].size(); i++)
		{
			int idx = vec[temp.end][i].end;
			int cost = vec[temp.end][i].cost;
			if (visit[idx] == 0)
			{

			}
		}
	}

}
int main()
{
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		vec[start].push_back({ end,cost });
	}
	cin >> v1 >> v2;
	findRoad(1);
}