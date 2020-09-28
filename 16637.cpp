#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
vector <long long int> first;
vector <char> second;
long long int MAX = -9999999999999999;
long long int cal(long long int a, long long int b, char c)
{
	long long int temp;
	if (c == '+')
		temp = a + b;
	if (c == '-')
		temp = a - b;
	if (c == '*')
		temp = a * b;
	return temp;
}
void find(int index , long long int value)
{
	if (index >= second.size())
	{
		if (value > MAX)
			MAX = value;
		return;
	}
	long long int temp = cal(value, first[index + 1], second[index]); // 지금과 그 다음 인덱스 계산
	find(index + 1, temp);
	if (second.size() > index+1 )
	{
		long long int temp2 = cal(first[index + 1], first[index + 2], second[index + 1]); // 그 다음 인덱스와 그 다다음 인덱스 계산
		temp = cal(value, temp2, second[index]);
		find(index + 2, temp);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	long long int value = 0;
	for (int i = 0; i < N; i++)
	{
		char c;
		cin >> c;
		if (c == '-' || c == '+' || c == '*')
		{
			first.push_back(value);
			second.push_back(c);
			value = 0;
		}
		else
			value = 10 * value + (c - '0');
	}
	first.push_back(value);
	if (N == 1)
		cout << first[0];
	else
	{
		find(0,first[0]);
		cout << MAX;
	}
}