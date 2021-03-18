#include<iostream>
#include<queue>
using namespace std;
int arr[21][21];
bool visit[21][21];
int N;
struct list
{
    int x;
    int y;
    int cnt = 0;
};
queue <list> que;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct compare { // 비교 함수
    bool operator() (list A, list B)
    {
        if (A.cnt == B.cnt)
        {
            if (A.x == B.x)
                return A.y > B.y;
            return A.x > B.x;
        }
        return A.cnt > B.cnt;
    }
};
void reset() // 방문 배열 초기화
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            visit[i][j] = false;
    }
}
void BFS()
{
    int size = 2;
    int eat = 0;
    int second = 0;
    while (1)
    {
        priority_queue < list, vector<list>, compare > fish;
        while (!que.empty()) // 먹이 체크 반복문
        {
            list temp = que.front();
            que.pop();
            visit[temp.x][temp.y] = true;
            for (int i = 0; i < 4; i++)
            {
                int nx = temp.x + dx[i];
                int ny = temp.y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && visit[nx][ny] == false)
                {
                    visit[nx][ny] = true;
                    list temp2;
                    temp2.x = nx;
                    temp2.y = ny;
                    temp2.cnt = temp.cnt + 1;
                    if (arr[nx][ny] > size)
                        continue;
                    if (arr[nx][ny] < size && arr[nx][ny] != 0)
                        fish.push({ nx, ny, temp.cnt + 1 });
                    que.push(temp2);
                }
            }
        }
        reset(); // 이제 먹이를 먹으러 가야해서 초기화
        if (!fish.empty())
        {
            list temp = fish.top();
            fish.pop();
            arr[temp.x][temp.y] = 0;
            visit[temp.x][temp.y] = true;
            second = temp.cnt;
            que.push(temp);
            eat++;
        }
        else
        {
            cout << second;
            return;
        }
        if (eat == size)
        {
            eat = 0;
            size++;
        }
    }
}
int main()
{
    cin >> N;
    list temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 9)
            {
                temp.x = i;
                temp.y = j;
                arr[i][j] = 0;
            }
        }
    }
    que.push(temp);
    BFS();
}