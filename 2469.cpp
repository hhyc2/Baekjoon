#include<stdio.h>
#pragma warning(disable:4996)
char arr[27];
char start[27];
char answer[27];
char line[1003][27];
int main()
{
	int n;
	int k;
	int stop;
	scanf("%d %d", &k, &n);
	scanf("%s", &arr); // 이렇게 끝나야한다
	for (int i = 0; i < k; i++)
		start[i] = 'A' + i;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &line[i]);
		if (line[i][0] == '?')
			stop = i;
	}
	for (int i = 0; i < stop; i++)
	{
		for (int j = 0; j <k-1; j++)
		{
			if (line[i][j] == '-')
			{
				char temp = start[j];
				start[j] = start[j + 1];
				start[j + 1] = temp;
			}
		}
	} // 시작 값 바꿔주고 
	for (int i = n - 1; i > stop; i--)
	{
		for (int j = 0; j<k-1; j++)
		{
			if (line[i][j] == '-')
			{
				char temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	} // 끝나는 값 바꿔주고
	// 이제는 비교해줘야지요? 

	for (int i = 0; i < k - 1; i++)
	{
		if (start[i] != arr[i])
			answer[i] = '-';
		else
			answer[i] = '*';
	}
	for (int i = 0; i<k-1; i++)
	{
		if (answer[i] == '-')
		{
			char temp = start[i];
			start[i] = start[i + 1];
			start[i + 1] = temp;
			answer[i + 1] = '*';
			i++;
		}
	}
	int flag = 0;
	for (int i = 0; i<k-1; i++)
	{
		if (start[i] != arr[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		for (int i = 0; i<k-1; i++)
			printf("%c", answer[i]);
	}
	else
	{
		for (int i = 0; i < k - 1; i++)
			printf("x");
	}
}