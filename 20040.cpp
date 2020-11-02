#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct list
{
	int first;
	int second;
};
vector <list> vec;
int parent[500001];
int N, M;
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
	cin >> N >> M;
	int order = 0;
	int flag = 0;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < M; i++)
	{
		list temp;
		cin >> temp.first >> temp.second;
		if(flag==0)
		{
			if (!isSame(temp.first, temp.second))
				unionSet(temp.first, temp.second);
			else
			{
				flag = 1;
				order = i + 1;
			}
		}
	}
	cout << order;
}