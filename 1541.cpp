#include<iostream>
#include<vector>
using namespace std;
string str;
vector <int> vec;
int main()
{
	cin >> str;
	int value = 0;
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			value *= 10;
			value = value + str[i]-'0';
		}
		else if(str[i] == '+')
		{
			sum += value;
			value = 0;
		}
		else
		{
			sum += value;
			vec.push_back(sum);
			sum = 0;
			value = 0;
		}
	}
	sum += value;
	vec.push_back(sum);
	sum = vec[0];

	for (int i = 1; i < vec.size(); i++)
		sum -= vec[i];
	cout << sum;
}