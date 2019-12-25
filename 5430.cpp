#include<stdio.h>
#include<iostream>
#include<deque>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
char arr[100001];
int main()
{
	freopen("5430.inp", "r", stdin);
	freopen("5430.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int num;
	int n;
	char c;
	for (int i = 0; i < T; i++)
	{
		int cnt = 0;
		int flag = 0;
		deque <int> deq;
		scanf("%s", &arr);
		scanf("%d\n", &n);
		scanf("%c", &c); // [ 받음
		if (n != 0)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d%c", &num, &c); // 숫자랑 , ] 받음
				deq.push_back(num);
			}
		}
		else
			scanf("%c%c", &c, &c);
		for (int j = 0; arr[j] != '\0'; j++)
		{
			if (arr[j] == 'R')
				cnt++;
			else if (arr[j] == 'D')
			{
				if (deq.empty())
				{
					flag = 1;
					break;
				}
				else
				{
					if (cnt % 2 == 0)
						deq.pop_front();
					else
						deq.pop_back();
				}
			}
		}
		if (cnt % 2 != 0)
			reverse(deq.begin(), deq.end());
		if (flag == 0)
		{
			int value = deq.size();
			printf("[");
			for (int j = 0; j < value; j++)
			{
				printf("%d", deq.front());
				deq.pop_front();
				if (j != value - 1)
					printf(",");
			}
			printf("]\n");
		}
		else
			printf("error\n");
	}
}