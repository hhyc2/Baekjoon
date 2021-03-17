#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int arr[501][501];
bool visit[501][501];
int dx[4] = {0,0,1,-1};
int dy[4] = { 1,-1,0,0 };
int MAX = -1;
void find(int x, int y, int cnt, int sum)
{
	if (cnt == 3)
	{
		MAX = max(MAX, sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] == true)
			continue;
		visit[nx][ny] = true;
		find(nx, ny, cnt + 1, sum + arr[nx][ny]);
		visit[nx][ny] = false;
	}
}
void mod(int x, int y)
{
	if (x >= 1 && y >= 1 && x + 1 < N)
		MAX = max(MAX, arr[x - 1][y] + arr[x][y] + arr[x + 1][y] + arr[x][y - 1]);
	if (x >= 1 && y+1 <M  && x + 1 < N)
		MAX = max(MAX, arr[x - 1][y] + arr[x][y] + arr[x + 1][y] + arr[x][y + 1]);
	if (x+1<M && y>=1 && y+1<M)
		MAX = max(MAX, arr[x][y] + arr[x][y-1] + arr[x][y+1] + arr[x+1][y]);
	if (x>=1 && y >= 1 && y + 1 < M)
		MAX = max(MAX, arr[x][y] + arr[x][y-1] + arr[x][y+1] + arr[x-1][y]);
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = true;
			find(i, j, 0 , arr[i][j]);
			mod(i, j);
			visit[i][j] = false;
		}
	}
	cout << MAX;
}