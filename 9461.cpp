#include<iostream>
using namespace std;
long long int dp[101];
void DP()
{
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 100; i++)
		dp[i] = dp[i - 3] + dp[i - 2];
}
int main()
{
	int Test;
	cin >> Test;
	DP();
	for (int i = 0; i < Test; i++)
	{
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
}