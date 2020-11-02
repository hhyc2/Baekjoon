#include<iostream>
using namespace std;
int arr[2200][2200];
int N;
int minusCnt;
int zeroCnt;
int oneCnt;
void find(int x, int y, int n)
{
	int temp = arr[x][y];
	int flag = 0;
	for (int i = x; i < x+n; i++)
	{
		for (int j = y; j < y+n; j++)
		{
			if(temp !=arr[i][j])
				flag=1;
		}
	}

	if (flag == 0)
	{
		if (temp == -1)
			minusCnt++;
		else if (temp == 0)
			zeroCnt++;
		else if(temp == 1)
			oneCnt++;
		return;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j< 3; j++)
				find(x + n / 3 * i, y + n / 3 * j, n/3);
		}
	}
}
int main()
{	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	find(0, 0, N);
	cout << minusCnt << "\n";
	cout << zeroCnt << "\n";
	cout << oneCnt << "\n";
}