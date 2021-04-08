// UnionFind 문제
#include<iostream>
#include<vector>
using namespace std;
int N, M, n;
int answer;
vector<int> know;
vector <int> party[51];
int parent[51]; // 
int Find_Parent(int a)
{
	if (a == parent[a])
		return a;
	return parent[a] = Find_Parent(parent[a]);
}
bool isSame(int a, int b)
{
	int A = Find_Parent(a);
	int B = Find_Parent(b);
	if (A == B)
		return true;
	else
		return false;
}
void setUnion(int a, int b)
{
	int A = Find_Parent(a);
	int B = Find_Parent(b);
	parent[B] = A;
}
void setting()
{
	for (int i = 1; i <= 50; i++)
		parent[i] = i;
	answer = M;
}
void FindAnswer()
{
	for (int i = 0; i < M; i++)
	{
		int a = party[i][0];
		for (int j = 1; j < party[i].size(); j++)
		{
			if (!isSame(a, party[i][j]))
				setUnion(a, party[i][j]);
		}
	}
	for (int i = 0; i < M; i++)
	{
		int flag = 0;
		for (int j = 0; j < know.size(); j++)
		{
			for (int k = 0; k < party[i].size(); k++)
			{
				if (flag == 1)
					break;
				if (isSame(know[j], party[i][k]))
					flag = 1;
			}
		}
		if (flag == 1)
			answer--;
	}
	cout << answer;
}
int main()
{
	cin >> N >> M;
	cin >> n;
	for (int i = 0; i < n; i++) // 아는 사람 입력
	{
		int temp;
		cin >> temp;
		know.push_back(temp);
	}
	for (int i = 0; i < M; i++) // 파티 입력
	{
		int person;
		cin >> person;
		for (int j = 0; j < person; j++)
		{
			int num;
			cin >> num;
			party[i].push_back(num);
		}
	}
	setting();
	FindAnswer();
}