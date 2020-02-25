#include<stdio.h>
#include<stack>
#pragma warning(disable:4996)
using namespace std;
char arr[1000001];
stack <char> left;
stack <char> right;
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", &arr);
		for (int j = 0; arr[j] != '\0'; j++)
		{
			if (arr[j] == '-')
			{
				if (!right.empty())
					right.pop();
			}
			else if (arr[j] == '<')
			{
				if (!right.empty())
				{
					char c = right.top();
					right.pop();
					left.push(c);
				}

			}
			else if (arr[j] == '>')
			{
				if (!left.empty())
				{
					char c = left.top();
					left.pop();
					right.push(c);
				}

			}
			else
				right.push(arr[j]);

		}
		while (!right.empty())
		{
			char c = right.top();
			right.pop();
			left.push(c);
		}
		while (!left.empty())
		{
			char c = left.top();
			left.pop();
			printf("%c", c);
		}
		printf("\n");
	}
}