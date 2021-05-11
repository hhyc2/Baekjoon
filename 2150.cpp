#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int N, M;
int visit[10001];
vector<int> vec[10001];
vector<int> vec2[10001];
vector<int> scc[100001];
vector<pair<int, int> > result;
stack<int> st;
int vec_index;
int cnt;
void dfs(int idx)
{
	visit[idx]++;
	for (int i = 0; i < vec[idx].size(); i++)
	{
		if (visit[vec[idx][i]] == 0)
			dfs(vec[idx][i]);
	}
	st.push(idx);
	return;
}
void backdfs(int idx, int vidx)
{
	scc[vidx].push_back(idx);
	visit[idx]++;
	for (int i = 0; i < vec2[idx].size(); i++)
	{
		if (visit[vec2[idx][i]] == 0)
			backdfs(vec2[idx][i], vidx);
	}
	return;
}
int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		vec[start].push_back(end);
		vec2[end].push_back(start);
	}
	for (int i = 1; i <= M; i++)
	{
		if (visit[i] == 0)
			dfs(i);
	}
	for (int i = 1; i <= M; i++)
		visit[i] = 0;
	while (!st.empty())
	{
		int top = st.top();
		st.pop();
		if (visit[top] == 0)
		{
			backdfs(top, vec_index);
			cnt++;
			vec_index++;
		}
	}
	for (int i = 0; i < vec_index; i++)
	{
		sort(scc[i].begin(), scc[i].end());
		result.push_back({ scc[i][0],i });
	}
	cout << cnt << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < scc[result[i].second].size(); j++)
			cout << scc[result[i].second][j] << " ";
		cout << "-1\n";
	}
	
}