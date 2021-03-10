#include<iostream>
using namespace std;
int main()
{
	int N;
	int M;
	string str;
	cin >> N >> M >> str;
	int result = 0;
	int temp = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I')
		{
			temp++;
			i++;
			if (temp == N)
			{
				temp--;
				result++;
			}
		}
		else
			temp = 0;
	}
	cout << result;
}