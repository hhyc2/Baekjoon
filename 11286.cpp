#include<iostream>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;
priority_queue < pair<int, int>, vector< pair <int, int> >, greater< pair <int, int> > > que;
int main()
{
	int Test;
	cin >> Test;
	for (int i = 0; i < Test; i++)
	{
		long long int num;
		cin >> num;
		if (num == 0)
		{
			if (que.empty())
				cout << "0\n";
			else
			{
				cout << que.top().second << "\n";
				que.pop();
			}
		}
		else
			que.push({ abs(num), num });
	}
}
