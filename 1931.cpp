#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct list
{
	int start;
	int end;
};
bool compare(const list& a, const list& b)
{
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}
vector <list> vec;
int main()
{
	int Test;
	cin >> Test;
	for (int i = 0; i < Test; i++)
	{
		list temp;
		cin >> temp.start >> temp.end;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end(), compare);
	int cnt = 1;
	int time = vec[0].end;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i].start >= time)
		{
			time = vec[i].end;
			cnt++;
		}
	}
	cout << cnt;
}