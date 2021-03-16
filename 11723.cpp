#include<iostream>
#pragma warning(disable:4996)
using namespace std;
bool visit[21];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int Test;
	cin >> Test;
	for (int i = 0; i < Test; i++)
	{
		string str;
		int num;
		cin >> str;
		if (str == "add")
		{
			cin >> num;
			visit[num] = true;
		}
		else if (str == "remove")
		{
			cin >> num;
			visit[num] = false;
		}
		else if (str == "check")
		{
			cin >> num;
			if (visit[num] == true)
				cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "toggle")
		{
			cin >> num;
			if (visit[num] == false)
				visit[num] = true;
			else
				visit[num] = false;
		}
		else if (str == "all")
		{
			for (int i = 1; i <= 20; i++)
				visit[i] = true;
		}
		else
		{
			for (int i = 1; i <= 20; i++)
				visit[i] = false;
		}
	}
}