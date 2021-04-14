#include<iostream>
#include<vector>
using namespace std;
struct list
{
	int idx;
	int cost;
};
vector<list> vec[10001];
int visit[10001];
int MAX = -1;
int MaxIndex;
void reset()
{
	for (int i = 0; i <= 10000; i++)
		visit[i] = 0;
	MAX = -1;
}
void dfs(int start, int cost)
{
	if (visit[start] != 0)
		return;
	visit[start] = 1;
	if (cost > MAX)
	{
		MAX = cost;
		MaxIndex = start;
	}
	for (int i = 0; i < vec[start].size(); i++)
		dfs(vec[start][i].idx, cost + vec[start][i].cost);
}
int main()
{
	int Test;
	cin >> Test;
	for (int i = 0; i < Test - 1; i++)
	{
		int start, end, value;
		cin >> start >> end >> value;
		vec[start].push_back({ end,value });
		vec[end].push_back({ start,value });
	}
	dfs(1, 0);
	reset();
	dfs(MaxIndex, 0);
	cout << MAX;
}