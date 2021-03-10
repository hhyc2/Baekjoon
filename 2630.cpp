#include<iostream>
using namespace std;
int N;
char arr[129][129];
int blue_count;
int white_count;
void back(int x, int y, int n)
{
	char save = arr[x][y];
	int flag = 0;
	for (int i = x; i < x + n; i++)
	{
		if (flag == 1)
			break;
		for (int j = y; j < y + n; j++)
		{
			if (save != arr[i][j])
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1)
	{
		back(x, y, n / 2);
		back(x, y + n / 2, n / 2);
		back(x + n / 2, y, n / 2);
		back(x + n / 2, y + n / 2, n / 2);
	}
	else
	{
		if (save == '0')
			white_count++;
		else
			blue_count++;
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
	back(0, 0, N);
	cout << white_count << "\n";
	cout << blue_count;
}