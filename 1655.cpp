#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
priority_queue<int, vector<int>, greater<int>> min_que;
priority_queue<int, vector<int>, less<int>>max_que;
int N;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		if (i % 2 == 0)
			max_que.push(num);
		else
			min_que.push(num);
		if (!min_que.empty() && max_que.top() > min_que.top())
		{
			int temp = max_que.top();
			max_que.pop();
			max_que.push(min_que.top());
			min_que.pop();
			min_que.push(temp);
		}
		printf("%d\n", max_que.top());
	}
}
