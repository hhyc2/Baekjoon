#include<iostream>
#include<algorithm>
using namespace std;
int N, R, C;
int value;
void back(int n, int x, int y) // x , y 시작 위치
{
	if (x == R && y == C)
	{
		cout << value;
		return;
	}
	if (x <= R && y <= C && x+n > R && y+n >C)
	{
		back(n / 2, x, y);
		back(n / 2, x, y + n / 2);
		back(n / 2, x + n/2, y);
		back(n / 2, x + n / 2 , y + n / 2);
	}
	else
		value = value + n * n;
}
int main()
{
	cin >> N >> R >> C;
	back(1 << N, 0, 0);
}