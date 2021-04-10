// 네트워크 플로우
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> vec[52];
int MaxWater[52][52];
int FlowWater[52][52];
int Prev[52];
int change(char temp)
{
	if (temp <= 'Z')
		return temp - 'A';
	return temp - 'a' + 26;
}
int main()
{
	int Test;
	cin >> Test;
	for (int i = 0; i < Test; i++)
	{
		char start;
		char end;
		int flow;
		cin >> start >> end >> flow;
		start = change(start);
		end = change(end);
		vec[start].push_back(end);
		vec[end].push_back(start);
		MaxWater[start][end] += flow;
		MaxWater[end][start] += flow;
	}
	int answer = 0;
	int start = 0;
	int end = 25;
	while (1)
	{
		for (int i = 0; i < 52; i++)
			Prev[i] = -1;
		queue<int>que;
		que.push(start);
		while (!que.empty())
		{
			int temp = que.front();
			que.pop();
			if (temp == end)
				break;
			for (int i = 0; i < vec[temp].size(); i++)
			{
				int next = vec[temp][i];
				if (Prev[next] == -1 && MaxWater[temp][next]-FlowWater[temp][next] > 0)
				{
					que.push(next);
					Prev[next] = temp;
				}
			}
		}
		if (Prev[end] == -1)
			break;
		int MIN = 1e9;
		for (int i = end; i != start; i = Prev[i])
			MIN = min(MIN, MaxWater[Prev[i]][i] - FlowWater[Prev[i]][i]);
		for (int i = end; i != start; i = Prev[i])
		{
			FlowWater[Prev[i]][i] += MIN;
			FlowWater[i][Prev[i]] -= MIN;
		}
		answer += MIN;
	}
	cout << answer;
}