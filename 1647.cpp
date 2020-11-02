#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int parent[100001];
int MAX = -1;
struct list
{
	int first;
	int second;
	int value;
};
bool compare(const list& a, const list& b)
{
	return a.value < b.value;
}
int findParent(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = findParent(parent[x]);
}
bool isSame(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x == y)
		return true;
	else
		return false;
}
void setUnion(int x, int y)
{
	x = findParent(x);
	y = findParent(y);
	if (x != y)
		parent[y] = x;
}
vector <list> vec;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		list temp;
		cin >> temp.first >> temp.second >> temp.value;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	int result = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		list temp = vec[i];
		if (!isSame(temp.first, temp.second))
		{
			setUnion(temp.first, temp.second);
			result += temp.value;
			MAX = max(MAX, temp.value);
		}
	}
	cout << result-MAX;
}