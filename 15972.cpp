#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N, M, H;
struct list
{
	int up;
	int down;
	int left;
	int right;
	int water;
};
list arr[1001][1001];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair <int, int> > > pq;
void popWater(int x, int y, int height)
{
	if (arr[x][y].water > height)
	{
		arr[x][y].water = height;
		pq.push({ height, 1001 * x + y });
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> H;
	long long int cnt = 0;
	for (int j = 0; j < N; j++) // 물 채우기
	{
		for (int k = 0; k < M; k++)
			arr[j][k].water = H;
	}
	for (int j = 0; j <= N; j++) // 위 아래 설정
	{
		for (int k = 0; k < M; k++)
		{
			cin >> arr[j][k].up;
			if (j != 0)
				arr[j - 1][k].down = arr[j][k].up;
		}
	}
	for (int j = 0; j < N; j++) // 좌 우측 설정
	{
		for (int k = 0; k <= M; k++)
		{
			cin >> arr[j][k].left;
			if (k != 0)
				arr[j][k - 1].right = arr[j][k].left;
		}
	}
	for (int j = 0; j < M; j++)
	{
		if (arr[0][j].up != -1) // 맨 위 탐색
			popWater(0, j, arr[0][j].up);
		if (arr[N - 1][j].down != -1) // 맨 아래 탐색 
			popWater(N - 1, j, arr[N - 1][j].down);
	}
	for (int j = 0; j < N; j++)
	{
		if (arr[j][0].left != -1) // 맨 좌측 탐색
			popWater(j, 0, arr[j][0].left);
		if (arr[j][M - 1].right != -1) // 맨 우측 탐색 
			popWater(j, M - 1, arr[j][M - 1].right);
	}
	while (!pq.empty())
	{
		int x = pq.top().second / 1001;
		int y = pq.top().second % 1001;
		int height = pq.top().first;
		pq.pop();
		if (arr[x][y].water != height)
			continue;
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				if (arr[x][y].left == -1 || y == 0)
					continue;
				int temp = max(arr[x][y].water, min(arr[x][y - 1].water, arr[x][y].left));
				if (arr[x][y - 1].water > temp)
				{
					arr[x][y - 1].water = temp;
					pq.push({ temp, x * 1001 + y-1 });
				}
			}
			else if (i == 1)
			{
				if (arr[x][y].right == -1 || y == M-1 )
					continue;
				int temp = max(arr[x][y].water, min(arr[x][y +1].water, arr[x][y].right));
				if (arr[x][y+1].water > temp)
				{
					arr[x][y+1].water = temp;
					pq.push({ temp, x * 1001 + y+1 });
				}
			}
			else if (i == 2)
			{
				if (arr[x][y].up == -1 || x == 0)
					continue;
				int temp = max(arr[x][y].water, min(arr[x-1][y].water, arr[x][y].up));
				if (arr[x-1][y].water > temp)
				{
					arr[x-1][y].water = temp;
					pq.push({ temp, (x-1) * 1001 + y });
				}
			}
			else
			{
				if (arr[x][y].down == -1 || x == N-1)
					continue;
				int temp = max(arr[x][y].water, min(arr[x+1][y].water, arr[x][y].down));
				if (arr[x +1][y].water > temp)
				{
					arr[x + 1][y].water = temp;
					pq.push({ temp, (x + 1) * 1001 + y });
				}
			}
		}
	}
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < M; k++)
			cnt += arr[j][k].water;
	}
	cout << cnt << "\n";
}
