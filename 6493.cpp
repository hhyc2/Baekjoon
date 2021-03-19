#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int N;
string str;
int index = 0;
bool Slump()
{
	if (str[index] == 'D' || str[index] == 'E')
		index++;
	else
		return false;
	while (index < str.size())
	{
		if (str[index] == 'F')
		{
			index++;
			if (str[index] == 'G')
			{
				index++;
				return true;
			}
			bool check = Slump();
			if (check == true)
				return true;
		}
		else
			return false;
	}
	return false;
}
bool Slimp()
{
	if (str[index] == 'A')
		index++;
	if (str[index] == 'H')
	{
		index++;
		return true;
	}
	if (str[index] == 'B')
	{
		index++;
		bool check = Slimp();
		if (str[index] == 'C' && check == true)
		{
			index++;
			return true;
		}
		else return false;
	}
	else
	{
		bool check = Slump();
		if (str[index] == 'C' && check == true)
		{
			index++;
			return true;
		}
		else
			return false;
	}
}
int main()
{
	//freopen("p384.inp", "r", stdin);
	//freopen("p384.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		index = 0;
		bool check = Slimp() && Slump();
		if (check == true && index == str.size())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
