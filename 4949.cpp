#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>
using namespace std;
stack<char> st;
int main()
{
	string str;
	while (1)
	{
		int flag = 0;
		getline(cin, str);
		if (str.size() == 1 && str[0] == '.')
			return 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (flag == 1)
				continue;
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);
			else if (str[i] == ')')
			{
				if (st.top() == '(')
					st.pop();
				else
					cout << "no" << "\n";
			}
			else if (str[i] == ']')
			{
				if (st.top() == '(')
					st.pop();
				else
					cout << "no" << "\n";
			}
		}
		while (!st.empty())
			st.pop();
		if(flag==0)
		cout << "yes" << "\n";
		flag = 0;
	}
}