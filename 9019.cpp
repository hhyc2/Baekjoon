#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
int start, finish;
int visit[10001];
int check[10001];
int dir[10001];
char arr[10001];
struct list
{
	int num;
	int cnt = 0;
};
queue <list> que;
// D 2배 S n-1 L 왼편으로 이동 R 우측으로 이동
int D(int num)
{
	int n = 2 * num;
	if (n > 9999)
		n = n % 10000;
	return n;
}
int S(int num)
{
	int n = num - 1;
	if (n == -1)
		n = 9999;
	return n;
}
int L(int num)
{
	int n = num / 1000;
	int temp = (num % 1000) * 10;
	return temp+n;
}
int R(int num)
{
	int n = num % 10;
	int temp = num / 10;
	return 1000 * n + temp;
}
void BFS()
{
	while (!que.empty())
	{
		list temp = que.front();
		que.pop();
		int num;
		if (temp.num == finish)
		{
			int i = 0;
			int x = finish;
			while (1)
			{
				if (x == start)
					break;
				if (dir[x] == 1)
					arr[i] = 'D';
				else if (dir[x] == 2)
					arr[i] = 'S';
				else if (dir[x] == 3)
					arr[i] = 'L';
				else
					arr[i] = 'R';
				x = check[x];
				i++;
			}
			for (int i = temp.cnt - 1; i >= 0; i--)
			{
				printf("%c", arr[i]);
			}
			printf("\n");
			return;
		}
		list A = temp;
		num = D(temp.num);
		if (visit[num] == 0)
		{
			visit[num]=1;
			check[num] = temp.num;
			dir[num] = 1;
			A.num = num;
			A.cnt = temp.cnt + 1;
			que.push(A);
		}
		num = S(temp.num);
		if (visit[num] == 0)
		{
			visit[num]=1;
			A.cnt = temp.cnt + 1;
			check[num] = temp.num;
			dir[num] = 2;
			A.num = num;
			que.push(A);
		}
		num = L(temp.num);
		if (visit[num] == 0)
		{
			check[num] = temp.num;
			dir[num] = 3;
			visit[num]=1;
			A.cnt = temp.cnt + 1;
			A.num = num;
			que.push(A);
		}
		num = R(temp.num);
		if (visit[num] == 0)
		{
			check[num] = temp.num;
			dir[num] = 4;
			visit[num]=1;
			A.cnt = temp.cnt + 1;
			A.num = num;
			que.push(A);
		}
	}
}
void reset()
{
	for (int i = 0; i <= 10000; i++)
		visit[i] = 0;
	while (!que.empty())
		que.pop();
}
int main()
{
	int Test;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d %d", &start, &finish);
		list temp;
		temp.num = start;
		visit[start] = 1;
		que.push(temp);
		BFS();
		reset();
	}
}