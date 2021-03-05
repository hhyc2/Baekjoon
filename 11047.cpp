#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> vec;
bool compare(const int & a, const int & b)
{
	return a > b;
}
int main()
{
	int N;
	int value;
	int cnt = 0;
	cin >> N >> value;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end(),compare);
	for (int i = 0; i < N; i++)
	{
		while (1)
		{
			if (value - vec[i] >= 0)
			{
				value -= vec[i];
				cnt++;
			}
			else
				break;
		}
	}
	cout << cnt;
}