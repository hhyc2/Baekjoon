#include<stdio.h>
#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
string str;
vector <int> vec;
int visit[100];
int flag = 0;
void back(int start)
{
	if (start == str.size())
	{
		if (flag == 0)
		{
			int vec_size = vec.size();
			for (int i = 0; i < vec_size; i++)
			{
				if (vec[i] > vec.size())
					return;
			}
			for (int i = 0; i < vec_size; i++)
				printf("%d ", vec[i]);
			flag = 1;
		}
	}
	int num = str[start] - '0';
	if (num > 0)
	{
		if (visit[num] == 0) // 1ÀÇ ÀÚ¸®
		{
			visit[num] = 1;
			vec.push_back(num);
			back(start + 1);
			visit[num] = 0;
			vec.pop_back();
		}
		if (start < str.size() - 1)
		{
			num = num * 10 + (str[start + 1] - '0');
			if (num <= 50 && visit[num] == 0)
			{
				visit[num] = 1;
				vec.push_back(num);
				back(start + 2);
				visit[num] = 0;
				vec.pop_back();
			}
		}
	}
}
int main()
{
	cin >> str;
	back(0);
}