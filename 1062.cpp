#include<stdio.h>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int N, K;
string str[51];
int visit[26];
int cnt;
void find_word(int start, int num)
{
	if (num == K)
	{
		int word_cnt = 0;
		for (int i = 0; i < N; i++)
		{
			int flag = 0;
			for (int j = 4; j < str[i].size() - 4; j++)
			{
				if (visit[str[i][j] - 'a'] == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				word_cnt++;
		}
		if (word_cnt > cnt)
			cnt = word_cnt;
	}
	for (int i = start; i < 26; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			find_word(i,num+1);
			visit[i] = 0;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &K);
	if (K >= 5)
		K = K - 5; // anta , tica 미리 빼주는 작업
	else
	{
		printf("0");
		return 0;
	}
	for (int i = 0; i < N; i++)
		cin >> str[i];
	visit[0] = 1; // a
	visit['c' - 'a'] = 1;
	visit['i' - 'a'] = 1;
	visit['n' - 'a'] = 1;
	visit['t' - 'a'] = 1;
	find_word(0,0);
	printf("%d", cnt);
}