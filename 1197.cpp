#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct list
{
	int start;
	int end;
	int value;
};
bool compare(const list& A, const list& B)
{
	return A.value < B.value;
}
vector <list> vec;
int parent[10001];
int V, E;
long long int result;
int findParent(int x) 
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = findParent(parent[x]);
}
bool isSame(int x, int y)
{
	x = findParent(x);
	y = findParent(y);
	if (x == y)
		return true;
	else
		return false;
}
void unionSet(int x, int y)
{
	x = findParent(x);
	y = findParent(y);
	if (x != y)
		parent[y] = x;
}
int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		list temp;
		cin >> temp.start >> temp.end >> temp.value;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 1; i <= V; i++)
		parent[i] = i;
	for (int i = 0; i < vec.size(); i++)
	{
		list temp = vec[i];
		if (!isSame(temp.start, temp.end))
		{
			result = result + temp.value;
			unionSet(temp.start, temp.end);
		}
	}
	cout << result;
}