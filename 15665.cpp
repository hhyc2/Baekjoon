#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int arr[10];
int temp[10];
int visit[10];
void back(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << temp[i] << " ";
		cout << "\n";
		return;
	}
	int num = -1;
	for (int i = 0; i < N; i++)
	{
		if (num != arr[i])
		{
			temp[cnt] = arr[i];
			num = arr[i];
			back(cnt + 1);
		}
		
	}
}	
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	back(0);
}