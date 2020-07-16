#include<stdio.h>
#include<vector>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int K;
int flag;
char arr[105];
bool check[1000001];
vector <int> vec;
int main()
{
	cin >> arr >> K;
	for (int i = 2; i < K; i++)
	{
		if (check[i] == false)
			vec.push_back(i);
		for (int j = 2; i * j <= K; j++)
			check[i * j] = true;
	}
	for (int i = 0; i<vec.size(); i++)
	{
		int sum = 0;
		for (int j = 0; arr[j] != '\0'; j++)
		{
			sum = sum * 10 + arr[j] - '0';
			sum = sum % vec[i];
		}
		if (sum == 0)
		{
			flag = 1;
			printf("BAD %d", vec[i]);
			return 0;
		}
	}
	if (flag == 0)
		printf("GOOD");
}