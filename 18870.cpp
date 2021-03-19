#include<iostream>
#include<algorithm>
using namespace std;
struct list
{
	int x;
	int index;
	long long int value;
};
bool compare(const list& a, const list& b)
{
	return a.value < b.value;
}
bool index(const list& a, const list& b)
{
	return a.index < b.index;
}
list arr[1000001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].value;
		arr[i].index = i;
	}
	sort(arr, arr + N, compare);
	int temp = arr[0].value;
	int temp_x = 0;
	arr[0].x = 0;
	for (int i = 1; i < N; i++)
	{
		if (arr[i].value > temp)
		{
			arr[i].x = temp_x+1;
			temp_x = arr[i].x;
			temp = arr[i].value;
		}
		else
			arr[i].x = temp_x;
	}
	sort(arr, arr + N, index);
	for (int i = 0; i < N; i++)
		cout << arr[i].x << " ";
}