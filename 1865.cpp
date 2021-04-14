#include<iostream>
#include<vector>
using namespace std;
int Test;
int N, M, W;
struct list
{
	int idx;
	int cost;
};
vector<list> vec[501];
int dist[501];
void reset()
{
	for (int i = 1; i <= N; i++)
		dist[i] = 1e9;
}
bool findRoad()
{
	reset();
	dist[1] = 0;
	int count = N - 1;
	while (count--)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				int next = vec[i][j].idx;
				int nCost = vec[i][j].cost;
				if (dist[next] > dist[i] + nCost)
					dist[next] = dist[i] + nCost;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			int next = vec[i][j].idx;
			int nCost = vec[i][j].cost;
			if (dist[next] > dist[i] + nCost)
				return true;
		}
	}
	return false;
}
int main()
{
	cin >> Test;
	for (int i = 0; i < Test; i++)
	{
		cin >> N >> M >> W;
		for (int j = 0; j < M; j++)
		{
			int start, end, cost;
			cin >> start >> end >> cost;
			vec[start].push_back({ end,cost });
			vec[end].push_back({ start,cost });
		}
		for (int j = 0; j < W; j++)
		{
			int start, end, cost;
			cin >> start >> end >> cost;
			vec[start].push_back({ end,-cost });
		}
		if (findRoad())
			cout << "YES\n";
		else
			cout << "NO\n";
		for (int j = 1; j <= N; j++)
			vec[j].clear();
	}
}