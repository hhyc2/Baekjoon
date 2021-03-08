#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, M;
int MIN = 1e9;
int MIN_NUM;
bool visit[101];
struct list {
	int point;
	int cnt = 1;
};
vector<int> vec[101];
queue <list> que;
void reset()
{
	for (int i = 1; i <= N; i++)
		visit[i] = false;
}
void find_route(int start)
{
	reset();
	int cnt = 0;
	visit[start] = true;
	while (!que.empty())
	{
		list temp = que.front();
		que.pop();
		for (int i = 0; i<vec[temp.point].size(); i++)
		{
			if (visit[vec[temp.point][i]] == false)
			{
				visit[vec[temp.point][i]] = true;
				cnt = cnt + temp.cnt;
				list temp2;
				temp2.point = vec[temp.point][i];
				temp2.cnt = temp.cnt + 1;
				que.push(temp2);
			}
		}
	}
	if (cnt < MIN)
	{
		MIN = cnt;
		MIN_NUM = start;
	}
		
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		vec[start].push_back(end);
		vec[end].push_back(start);
	}
	for (int i = 0; i < N; i++)
		sort(vec[i].begin(), vec[i].end());
	for (int i = 2; i <= N; i++)
	{
		list temp;
		temp.point = i;
		que.push(temp);
		find_route(i);
	}
	cout << MIN_NUM;
}