#include<iostream>
using namespace std;
int main()
{
	int N;
	int num = 0;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		int temp = i;
		while (!(temp%5))
		{
			num++;
			temp = temp / 5;
		}
	}
	cout << num;
}