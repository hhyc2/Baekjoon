#include<stdio.h>
#include<iostream>
#include<stack>
#pragma warning(disable:4996)
using namespace std;
//  배열로 하면 구현 까다로운데 ㅅㅂ;
int main()
{
	stack <char> left;
	stack <char> right;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		left.push(str[i]);

	char c;
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		cin >> c;
		if (c == 'L')
		{
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
		}
		else if (c == 'D')
		{
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
		}
		else if (c == 'B')
		{
			if (!left.empty())
				left.pop();
		}
		else if (c == 'P')
		{
			cin >> c;
			left.push(c);
		}
	}
	int num = left.size();
	for (int i = 0; i < num; i++)
	{
		right.push(left.top());
		left.pop();
	}
	num = right.size();
	for (int i = 0; i < num; i++)
	{
		printf("%c", right.top());
		right.pop();
	}
}