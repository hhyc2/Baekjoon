#include<iostream>
#include<string>
#include<algorithm>
int parent[1000001];
int N, M;
using namespace std;
int findParent(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = findParent(parent[a]);
}
bool isSame(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a == b)
		return true;
	else return false;
}
void setUnion(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if(a!=b)
	parent[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			if (isSame(b, c))
				cout << "YES"<<"\n";
			else
				cout << "NO"<<"\n";
		}
		else
			setUnion(b, c);
	}
}