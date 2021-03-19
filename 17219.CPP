#include<iostream>
#include<map>
using namespace std;
map <string, string> m;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N; 
	int Test;
	cin >> N >> Test;
	for (int i = 0; i < N; i++)
	{
		string str, str1;
		cin >> str>> str1;
		m.insert(pair<string, string>(str, str1));
	}
	for (int i = 0; i < Test; i++)
	{
		string str;
		cin >> str;
		cout << m[str] << "\n";
	}
}