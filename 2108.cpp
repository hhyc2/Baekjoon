#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[500001];
int cnt[8002];
int Max_Cnt = -1;
vector<int>vec;
int main()
{
	int N;
	double sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] < 0)
			cnt[abs(arr[i])+4000]++;
		else
			cnt[arr[i]]++;
	}
	sort(arr, arr + N);
	int MIN = arr[0];
	int MAX = arr[N - 1];
	sum /= N;
	if (sum + 0.5 >= (int)sum + 1 && sum >= 0)
		sum = sum + 1;
	else if (sum < 0 && sum - 0.5 <= (int)sum - 1)
		sum = sum - 1;
	for (int i = 0; i <= 8000; i++)
	{
		if (cnt[i] > Max_Cnt)
		{
			Max_Cnt = cnt[i];
			vec.clear();
			if (i > 4000)
				vec.push_back((i - 4000) * -1);
			else
				vec.push_back(i);
		}
		else if (cnt[i] == Max_Cnt)
		{
			if (i > 4000)
				vec.push_back((i - 4000) * -1);
			else
				vec.push_back(i);
		}
	}
	sort(vec.begin(), vec.end());
	cout << int(sum) << "\n";
	cout << arr[N / 2] << "\n";
	if (vec.size() != 1)
		cout << vec[1] << "\n";
	else
		cout << vec[0] << "\n";
	cout << MAX - MIN << "\n";
}