#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int dist[1001];
bool visit[1001];
int N;
int M;
priority_queue< pair <int, int>, vector< pair < int, int > >, greater < pair < int, int > > > que;
struct list {
	int end;
	int value;
};
vector <list> vec[1001];
void find(int start)
{
	que.push({ 0,start });
	while (!que.empty())
	{
		int cost = que.top().first;
		int index = que.top().second;
		que.pop();
		if (visit[index])
			continue;
		visit[index] = true;
		dist[index] = cost;
		for (int i = 0; i < vec[index].size(); i++)
		{
			if (visit[vec[index][i].end])
				continue;
			vec[index][i].value += cost;
			que.push({ vec[index][i].value , vec[index][i].end});
		}
	}
}
int main()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		list temp;
		int first;
		int second;
		int value;
		cin >> first >> second >> value;
		temp.end = second;
		temp.value = value;
		vec[first].push_back(temp);
	}
	int start;
	int end;
	cin >> start >> end;
	for (int i = 1; i <= N; i++)
		dist[i] = 1e9;
	dist[start] = 0;
	find(start);
	cout << dist[end];
}

