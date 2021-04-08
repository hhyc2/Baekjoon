#include<iostream>
#include<queue>
using namespace std;
int N, M;
int arr[101];
int cnt[101];
// BFS
void find()
{
	queue <int> que;
	que.push(1);
	while (!que.empty())
	{
		int num = que.front();
		que.pop();
		for (int i = 1; i <= 6; i++)
		{
			int temp = num + i;
			if (temp > 100)
				continue;
			if (arr[temp] != 0)
				temp = arr[temp];
			if (cnt[temp] == 0)
			{
				cnt[temp] = cnt[num] + 1;
				que.push(temp);
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int first, second;
		cin >> first >> second;
		arr[first] = second;
	}
	for (int i = 0; i < M; i++)
	{
		int first, second;
		cin >> first >> second;
		arr[first] = second;
	}
	find();
	cout << cnt[100];
}