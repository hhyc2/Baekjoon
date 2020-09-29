#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr[51][51];
char arr2[51][51];
bool visit[51][51]; // 초기값 0 
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
int N;
int cnt;
int tired = 999999999;
vector <int> vec;
struct list
{
	int x;
	int y;
};
int dfs(int x, int y, int low_height, int high_height)
{
	if (arr[x][y] > high_height || arr[x][y] < low_height)
		return 0;
	int house = 0;
	if (arr2[x][y] == 'K')
		house++;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] )
			continue;
		visit[nx][ny] = true;
		house = house + dfs(nx, ny, low_height, high_height);
	}
	return house;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	list temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr2[i][j];
			if (arr2[i][j] == 'P') // 시작점 표시
			{
				temp.x = i;
				temp.y = j;
				visit[temp.x][temp.y] = true;
			}
			if (arr2[i][j] == 'K') // 목적지 표시 
				cnt++;
		}
	
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			vec.push_back(arr[i][j]);
		}
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end()); // 중복 제거 
	int low = 0;
	int high = 0;
	while (low <= high && high<vec.size())
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				visit[i][j] = false;
		}
		visit[temp.x][temp.y] = true;
		int value = dfs(temp.x, temp.y, vec[low], vec[high]);
		if (value == cnt)
		{
			if (tired > vec[high] - vec[low])
				tired = vec[high] - vec[low];
			low++;
		}
		else
			high++;
	}
	cout << tired;
	
}