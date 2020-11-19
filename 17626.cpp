#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int N;
int dp[50001];
int main()
{
	cin >> N;
	for (int i = 1; i*i<= N; i++)
		dp[i * i] = 1; // ������ 1 ó��

	for (int i = 2; i <= N; i++)
	{
		int MIN = 1e9;
		for (int j = sqrt(i); j >0; j--)
		{
			MIN = min(MIN, dp[i - j * j]+dp[j*j]);
		}
		dp[i] = MIN;
	}
	cout << dp[N];
}