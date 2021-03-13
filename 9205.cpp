#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
int startX, startY;
bool visit[102];
struct list
{
	int x;
	int y;
};
vector <list> vec;
void BFS()
{
	queue <list> que;
	list tmp;
	tmp.x = startX;
	tmp.y = startY;
	que.push(tmp);
	while (!que.empty())
	{
		int x = que.front().x;
		int y = que.front().y;
		que.pop();
		for (int i = 0; i < vec.size(); i++)
		{
			if (abs(x - vec[i].x) + abs(y - vec[i].y) <= 1000 && visit[i] == false)
			{
				visit[i] = true;
				que.push(vec[i]);
			}
		}
	}
}
void reset(int num)
{
	for (int i = 0; i <= num; i++)
		visit[i] = false;
	while (!vec.empty())
		vec.pop_back();
}
int main()
{
	int Test;
	cin >> Test;
	for (int i = 0; i < Test; i++)
	{
		int num;
		cin >> num;
		cin >> startX >> startY;
		for (int j = 0; j <= num; j++)
		{
			list temp;
			cin >> temp.x >> temp.y;
			vec.push_back(temp);
		}
		BFS();
		if (visit[num] == true)
			cout << "happy\n";
		else
			cout << "sad\n";
		reset(num);
	}
}