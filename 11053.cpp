#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int MAX = -1;
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[i] <= dp[j])
					dp[i] = dp[j] + 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
		MAX = max(dp[i], MAX);
	cout << MAX+1;
}