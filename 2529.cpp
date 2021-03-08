#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool visit[11];
char arr[11];
int N;
string temp = "";
vector <string> vec;
bool compare(const string& a, const string& b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > b[i])
			return true;
		else if (a[i] < b[i])
			return false;
		else
			continue;
	}
}
void back(int start, int cnt)
{
	if (cnt == N)
	{
		string tmp = "";
		for (int i = 0; i <= N; i++)
			tmp += arr[i];
		vec.push_back(tmp);
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (visit[i] == false) {
			if (temp[cnt] == '<')
			{
				if (start < i)
				{
					arr[cnt + 1] = '0'+i;
					visit[i] = true;
					back(i, cnt + 1);
					visit[i] = false;
				}
			}
			else
			{
				if (start > i)
				{
					arr[cnt + 1] = '0' + i;
					visit[i] = true;
					back(i, cnt + 1);
					visit[i] = false;
				}
			}
		}
	}
}
int main()
{
	cin >> N;
	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		temp += tmp[0];
	}
	for (int i = 0; i <= 9; i++)
	{
		arr[0] = '0'+i;
		visit[i] = true;
		back(i, 0);
		visit[i] = false;
	}
	sort(vec.begin(), vec.end(),compare);
	cout << vec[0] << "\n";
	cout << vec[vec.size()-1] << "\n";
}