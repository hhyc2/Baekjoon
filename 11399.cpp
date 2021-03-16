#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];
int main()
{
	int N;
	int answer = 0;
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		answer = answer + sum + arr[i];
		sum += arr[i];
	}
	cout << answer;
		
}