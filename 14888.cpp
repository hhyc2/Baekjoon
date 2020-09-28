#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int arr[12];
int c[4];
int MIN = 999999999;
int MAX = -999999999;
int N;
int cal(int a, int b, char temp)
{
	if (temp == '+')
		return a + b;
	else if (temp == '-')
		return a - b;
	else if (temp == '*')
		return a * b;
	else 
		return a / b;
}
void back(int index, int value, int plusCount, int minusCount, int mulCount, int divCount)
{
	if (index == N-1)
	{
		if (value > MAX)
			MAX = value;
		if (value < MIN)
			MIN = value;
		return;
	}
	
	if (plusCount<c[0])
	{
		int temp = cal(value, arr[index + 1], '+');
		back(index + 1, temp, plusCount + 1, minusCount, mulCount, divCount);
	}
	if (minusCount < c[1])
	{
		int temp = cal(value, arr[index + 1], '-');
		back(index + 1, temp, plusCount, minusCount+1, mulCount, divCount);
	}
	if (mulCount < c[2])
	{
		int temp = cal(value, arr[index + 1], '*');
		back(index + 1, temp, plusCount, minusCount, mulCount+1, divCount);
	}
	if(divCount < c[3])
	{
		int temp = cal(value, arr[index + 1], '/');
		back(index + 1, temp, plusCount, minusCount, mulCount, divCount+1);
	}
	return;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> c[i];
	back(0, arr[0], 0,0,0,0);
	cout << MAX << "\n";
	cout << MIN;
}