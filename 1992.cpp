#include<iostream>
using namespace std;
char arr[65][65];
int N;
void divide(int num, int x, int y)
{
	char save = arr[x][y];
	int flag = 0;
	for (int i = x; i < x+ num; i++)
	{
		if (flag == 1)
			break;
		for (int j = y; j < y +num; j++)
		{
			if (flag == 1)
				break;
			if (save != arr[i][j])
				flag = 1;
		}
	}
	if (flag == 1)
	{
		cout << "(";
		divide(num / 2, x, y);
		divide(num / 2, x, y + num / 2);
		divide(num / 2, x + num / 2, y);
		divide(num / 2, x + num / 2, y + num / 2);
		cout << ")";
	}
	else
		cout << save;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	divide(N,0,0);
}