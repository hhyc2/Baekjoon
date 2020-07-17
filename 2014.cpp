#include<stdio.h>
#include<queue>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int K, N;
priority_queue<int, vector<int>, greater<int>> que;
int sosu[100001];
long long int max_value = (long long int) 1 << 31 ;
int main()
{
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &sosu[i]);
		que.push(sosu[i]);
	}
	while (--N)
	{
		long long int temp = que.top();
		que.pop();
		for (int i = 0; i < K; i++)
		{
			long long int value = temp * sosu[i];
			if (value >= max_value)
				break;
			que.push(value);
			if (temp % sosu[i] == 0)
				break;
		}
	}
	printf("%d", que.top());
}
