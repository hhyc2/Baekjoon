#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int arr[10];
int temp[10];
int visit[10];
void back(int start,int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << temp[i] << " ";
		cout << "\n";
	}
	int num = -1;
	for (int i = start; i < N; i++)
	{
		if (visit[i]==0 && num != arr[i])
		{
			visit[i]++;
			temp[cnt] = arr[i];
			num = arr[i];
			back(i, cnt + 1);
			visit[i]--;
		}
	}
}	
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	back(0,0);
}