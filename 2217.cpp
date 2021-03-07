#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vec;
bool compare(const int& A, const int& B)
{
	return A > B;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end(), compare);
	int MAX = -1;
	for (int i = 0; i < N; i++)
		MAX = max(MAX, vec[i] * (i + 1));
	cout << MAX;
}
