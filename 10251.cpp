#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int N, M, L, G; // L 주행시간 , G 는 연료량
struct list
{
	int right;
	int down;
};
list arr[101][101];
int dp[101][101][202][2];
int flag;
int main()
{
	freopen("drive.inp", "r", stdin);
	freopen("drive.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int Test;
	cin >> Test;
	for (int i = 0; i < Test; i++)
	{
		cin >> N >> M >> L >> G;
		for (int ii = 0; ii < N; ii++) // 초기화 작업
		{
			for (int j = 0; j < M; j++)
			{
				for (int k = 0; k <= N + M; k++)
				{
					for (int l = 0; l < 2; l++)
						dp[ii][j][k][l] = 1e9;
				}
			}
		}
		flag = 0;
		dp[0][0][0][0] = dp[0][0][0][1] = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M - 1; k++)
				cin >> arr[j][k].right;
		} // 가로 가중치 입력
		for (int j = 0; j < N - 1; j++)
		{
			for (int k = 0; k < M; k++)
				cin >> arr[j][k].down;
		} // 세로 가중치 입력 
		for (int j = 1; j < M; j++)
			dp[0][j][0][0] = dp[0][j - 1][0][0] + arr[0][j - 1].right; // 가로 부분 세팅
		for (int j = 1; j < N; j++)
			dp[j][0][0][1] = dp[j - 1][0][0][1] + arr[j - 1][0].down; // 세로 부분 세팅
		for (int ii = 1; ii < N; ii++)
		{
			for (int j = 1; j < M; j++)
			{
				for (int k = 1; k <= N + M; k++)
				{
					dp[ii][j][k][0] = min(dp[ii][j - 1][k][0] + arr[ii][j - 1].right, dp[ii][j - 1][k - 1][1] + arr[ii][j - 1].right);
					dp[ii][j][k][1] = min(dp[ii - 1][j][k][1] + arr[ii - 1][j].down, dp[ii - 1][j][k - 1][0] + arr[ii - 1][j].down);
				}
			}
		}
		for (int k = 0; k <= N + M; k++)
		{
			if (dp[N - 1][M - 1][k][0] <= G)
			{
				cout << (N + M - 2) * L + k << "\n";
				flag = 1;
				break;
			}
			if (dp[N - 1][M - 1][k][1] <= G)
			{
				cout << (N + M - 2) * L + k << "\n";
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "-1\n";
	}
}