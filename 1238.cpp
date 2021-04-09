// 다익스트라 알고리즘
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, X;
int MAX = -1;
struct list
{
	int end;
	int value;
};
vector <list> vec[1001];
int findRoad(int start, int end)
{
	int dist[1001];
	for (int i = 1; i <= 1000; i++)
		dist[i] = 1e9;
	dist[start] = 0;
	priority_queue < pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({ 0,start });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int index = pq.top().second;
		pq.pop();
		for (int i = 0; i < vec[index].size(); i++)
		{
			int tempCost = cost + vec[index][i].value;
			int next = vec[index][i].end;
			if (dist[next] > tempCost)
			{
				dist[next] = tempCost;
				pq.push({ tempCost,next });
			}
		}
	}
	return dist[end];
}
int main()
{
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		int first, second, value;
		cin >> first >> second >> value;
		list temp;
		temp.end = second;
		temp.value = value;
		vec[first].push_back(temp);
	}
	for (int i = 1; i <= N; i++)
	{
		int first = findRoad(i,X);
		int second = findRoad(X,i);
		MAX = max(first + second, MAX);
	}
	cout << MAX;

}