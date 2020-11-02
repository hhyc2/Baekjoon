#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[1001];
int arr[1001];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		int MAX = dp[i];
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				MAX = max(dp[i] + dp[j], MAX);
		}
		dp[i] = MAX;
	}
	int MAX = -1;
	for (int i = 0; i < N; i++)
	{
		MAX = max(MAX, dp[i]);
	}
	cout << MAX;
}