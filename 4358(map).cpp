#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
#pragma warning(disable:4996)
using namespace std;
map <string, int> m;
int total_count;
int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	string str;
	cout << fixed; // 정수 출력
	cout.precision(4); // 소수 출력
	while (getline(cin, str))
	{
		if (m.find(str) == m.end())
			m.insert({ str, 1 });
		else
			m[str]++;
		total_count++;
	}
	map <string, int>::iterator iter = m.begin();
	for (iter; iter != m.end(); iter++)
		cout << iter->first << " " << iter->second / (double)total_count * 100 << "\n";
}