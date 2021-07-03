#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, L;
vector<int> vec;
int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	int min = vec[0];
	int cnt = 1;
	for (int i = 1; i < N; i++)
	{
		if (vec[i] - min > L-1)
		{
			cnt++;
			min = vec[i];
		}
	}
	cout << cnt;
}