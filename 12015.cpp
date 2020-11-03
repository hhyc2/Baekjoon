#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> vec;
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (vec.size() == 0 || vec.back() <num)
			vec.push_back(num);
		else
		{
			auto p = lower_bound(vec.begin(), vec.end(), num);
			*p = num;
		}
	}
	cout << vec.size();
}