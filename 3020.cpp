#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int N;
int H;
int bottom[100001];
int top[100001];
int value = 1e9;
int cnt;
int search1(int left, int right, int height)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (bottom[mid] >= height)
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}
int search2(int left, int right, int height)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (top[mid] >= height)
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> H;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			cin >> bottom[i / 2];
		else
			cin >> top[i / 2];
	}
	sort(bottom, bottom + N / 2);
	sort(top, top + N / 2);
	for (int i = 1; i <= H; i++)
	{
		int sum = 0;
		int first = search1(0, N / 2, i);
		int second = search2(0, N / 2, H-i+1);
		sum = N - (first + second);
		if (sum < value)
		{
			value = sum;
			cnt = 1;
		}
		else if (sum == value)
			cnt++;
	}
	cout << value << " " << cnt;
}