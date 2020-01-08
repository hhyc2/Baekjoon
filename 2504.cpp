#include<stdio.h>
#include<stack>
#pragma warning(disable:4996)
using namespace std;
char arr[50];
int main()
{
	stack <char> st;
	scanf("%s", &arr);
	int value = 1;
	int sum = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == '(')
		{
			st.push('(');
			value = value * 2;
			if (arr[i + 1] == ')')
				sum = sum + value;
		}	
		else if (arr[i] == '[')
		{
			st.push('[');
			value = value * 3;
			if (arr[i + 1] == ']')
				sum = sum + value;
		}
		else if (arr[i] == ')')
		{
			if (st.empty())
			{
				sum = 0;
				break;
			}
			else
			{
				value = value / 2;
				if (st.top() == '(')
					st.pop();
			}

		}
		else if (arr[i] == ']')
		{
			if (st.empty())
			{
				sum = 0;
				break;
			}
			else
			{
				value = value / 3;
				if (st.top() == '[')
					st.pop();
			}
		}
	}
	if (!st.empty())
		sum = 0;
	printf("%d", sum);
}