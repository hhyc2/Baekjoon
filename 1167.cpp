#include<iostream>
#include<vector>
using namespace std;
int V;
struct list {
	int idx;
	int value;
};
vector<list> vec[100001];
int visit[100001];
int answer = -1;
int place = 0;
void DFS(int start, int cost)
{
	if (visit[start] == 1)
		return;
	visit[start] = 1;
	if (answer < cost)
	{
		answer = cost;
		place = start;
	}	
	for (int i = 0; i < vec[start].size(); i++)
		DFS(vec[start][i].idx,cost+vec[start][i].value);
}
void reset()
{
	answer = -1;
	for (int i = 0; i <= V; i++)
		visit[i] = 0;
}
int main()
{
	cin >> V;
	for (int i = 0; i < V; i++)
	{
		int num;
		cin >> num;
		while (1)
		{
			int idx;
			int value;
			cin >> idx;
			if (idx== -1)
				break;
			else
			{
				cin >> value;
				vec[num].push_back({ idx,value });
				vec[idx].push_back({ num,value });
			}
		}
	}
	DFS(1, 0);
	reset();
	DFS(place, 0);
	cout << answer;
}