#include<iostream>
using namespace std;
int N, M;
int arr[100001];
long long int sum[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		cout << sum[end] - sum[start - 1] << "\n";
	}
}