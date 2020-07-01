#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
int N, M;
char map[51][51];
int visit[51][51];
int map_count[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt;
int flag;
int search(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] =='H')
		return 0;
	if (visit[x][y] == 1)
		return 1e9;
	if (map_count[x][y] != 0)
		return map_count[x][y];
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int	num = map[x][y] - '0';
		int nx = x + dx[i]*num;
		int ny = y + dy[i]*num;
		int value = search(nx, ny) + 1;
		if (value > map_count[x][y])
			map_count[x][y] = value;
	}
	visit[x][y] = 0;
	return map_count[x][y];
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", &map[i]);
	int value = search(0, 0);
	if (value >= 1e9)
		printf("-1");
	else
		printf("%d", value);
}