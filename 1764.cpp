#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector <string > first;
vector<string> answer;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		first.push_back(str);
	}
	sort(first.begin(), first.end());
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		int low = 0;
		int high = N - 1;
		while (low <= high)
		{
			int mid = (low + high)/2;
			if (str == first[mid])
			{
				answer.push_back(str);
				break;
			}
			else if (str < first[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";
}