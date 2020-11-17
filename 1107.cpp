#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool check[10];
int N;
int main()
{
	int num;
	cin >> N;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		check[a] = true;
	}
	int value = abs(N - 100); // + , -  로 올라갈 수 있는 횟수
	for (int i = 0; i <= 1000000 ; i++)
	{
		string str = to_string(i);
		int sz = 0;
		int flag = 0;
		for (int j = 0; j < str.size(); j++)
		{
			if (check[str[j] - '0'] == true)
			{
				flag = 1;
				break;
			}
			sz++;
		}
		if(flag==0)
		value = min(value, abs(N - i) + sz);
	}
	cout << value;
}