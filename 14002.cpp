#include<iostream>
#include<stack>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int index[1001];
int MAX = -1;
stack<int>st;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] <= dp[j])
			{
				index[i] = j;
				dp[i] = dp[j] + 1;
				if (MAX < dp[i])
					MAX = dp[i];
			}
		}
	}
	if (MAX == -1)
	{
		cout << 1 << "\n";
		cout << arr[0];
	}
	else
	{
		cout << MAX + 1 << "\n";
		for (int i = 0; i < N; i++)
		{
			if (dp[i] == MAX)
			{
				int temp = i;
				for (int j = MAX; j >= 0; j--)
				{
					st.push(arr[temp]);
					temp = index[temp];
				}
				while (!st.empty())
				{
					cout << st.top() << " ";
					st.pop();
				}
				return 0;
			}
		}
	}
	
}