#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int N;
	string str;
	cin >> N >> str;
	long long int sum = 0;
	long long int M = 1234567891;
	long long int j = 1;
	
	for (int i = 0; i < N; i++)
	{
		sum += (str[i] - 'a' + 1) * j;
		sum %= M;
		j *= 31;
		j %= M;
	}
	cout << sum;
}