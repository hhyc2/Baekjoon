#include<iostream>
#include<queue>
using namespace std;
int N, M;
int arr[101][101];
int visit[101][101];
int cheeze, cnt;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct list
{
	int x;
	int y;
};
void reset()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			visit[i][j] = 0;
	}
}
void findCheeze()
{
	cheeze = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
				cheeze++;
		}
	}
}
void findAir()
{
	reset();
	queue<list>que;
	que.push({ 0,0 });
	visit[0][0] = 1;
	while (!que.empty())
	{
		list temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && visit[nx][ny] == 0 && arr[nx][ny] == 0)
			{
				visit[nx][ny] = 1;
				que.push({ nx,ny });
			}
		}

	}
}
void findMeltCheeze()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)		
			{
				int airCount = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && visit[nx][ny] == 1)
						airCount++;
				}
				if (airCount >= 2)
					arr[i][j] = 0;
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	while (1)
	{
		findCheeze();
		if (cheeze == 0)
		{
			cout << cnt;
			return 0;
		}
		findAir();
		findMeltCheeze();
		cnt++;
	}
}