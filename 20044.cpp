#include<iostream>
#include<algorithm>
using namespace std;
int arr[10001];
int MIN = 1e9;
int main()
{
	int Test;
	cin >> Test;
	for (int i = 0; i < Test * 2; i++)
		cin >> arr[i];
	sort(arr, arr + (2 * Test));
	for (int i = 0; i < Test * 2; i++)
	{
		int value = arr[i] + arr[Test*2 - i - 1];
		if (value < MIN)
			MIN = value;
	}
	cout << MIN;
}