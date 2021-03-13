#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
priority_queue<pair <int, int> > maxHeap;
priority_queue<pair <int, int>, vector<pair< int, int> >, greater<pair <int, int> > > minHeap;
bool visit[1000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int Test;
	cin >> Test;
	for (int i = 0; i < Test; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			char c;
			int num;
			cin >> c >> num;
			if (c == 'I')
			{
				maxHeap.push({ num,j });
				minHeap.push({ num,j });
				visit[j] = true;
			}
			else
			{
				if (num == 1) // ÃÖ´ñ°ª »èÁ¦
				{
					while (!maxHeap.empty() && visit[maxHeap.top().second] == false)
						maxHeap.pop();
					if (!maxHeap.empty())
					{
						visit[maxHeap.top().second] = false;
						maxHeap.pop();
					}
				}
				else // ÃÖ¼Ú°ª »èÁ¦ 
				{
					while (!minHeap.empty() && visit[minHeap.top().second] == false)
						minHeap.pop();
					if (!minHeap.empty())
					{
						visit[minHeap.top().second] = false;
						minHeap.pop();
					}
				}
			}
		}
		while (!maxHeap.empty() && visit[maxHeap.top().second] == false)
			maxHeap.pop();
		while (!minHeap.empty() && visit[minHeap.top().second] == false)
			minHeap.pop();
		if (maxHeap.empty() && minHeap.empty())
			cout << "EMPTY\n";
		else
			cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
		while (!maxHeap.empty())
			maxHeap.pop();
		while (!minHeap.empty())
			minHeap.pop();
		for (int j = 0; j < n; j++)
			visit[j] = false;
	}
}