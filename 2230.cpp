#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int N, M;
vector <int> vec;
int value = 1e10;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()),vec.end()); // 중복 제거
	int low = 0;
	int high = 0;
	while (low <= high && high < vec.size())
	{
		if (vec[high] - vec[low] >= M)
		{
			if (value > vec[high] - vec[low])
				value = vec[high] - vec[low];
			low++;
		}
		else
			high++;
	}
	cout << value;

}