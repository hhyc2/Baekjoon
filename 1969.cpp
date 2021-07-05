#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector <string> vec;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		vec.push_back(str);
	}
	string value = "";
	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		int arr[4] = { 0, };
		for (int j = 0; j < N; j++)
		{
			if (vec[j][i] == 'A')
				arr[0]++;
			else if (vec[j][i] == 'T')
				arr[3]++;
			else if (vec[j][i] == 'G')
				arr[2]++;
			else if (vec[j][i] == 'C')
				arr[1]++;
		}
		int MAX = -1;
		int idx;
		for (int j = 0; j < 4; j++)
		{
			if (MAX < arr[j])
			{
				MAX = arr[j];
				idx = j;
			}
		}
		if (idx == 0)
		{
			value += "A";
			cnt = cnt + (N - arr[0]);
		}
		else if (idx == 1)
		{
			value += "C";
			cnt = cnt + (N - arr[1]);
		}
		else if (idx == 2)
		{
			value += "G";
			cnt = cnt + (N - arr[2]);
		}
		else if (idx == 3)
		{
			value += "T";
			cnt = cnt + (N - arr[3]);
		}
		
	}
	cout << value << "\n";
	cout << cnt;
}