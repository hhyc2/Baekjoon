#include<stdio.h>
#include<iostream>
#pragma warning(disable:4996)
char arr[11][10];
int check[10];
int alphabet[10];
int cnt;
int visit[10];
int value;
int save[100];
int N;
using namespace std;
string str[10];
void back(int start)
{
	if (start == cnt)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int mul = 1;
			for (int j = str[i].size()-1; j >= 0; j--)
			{
				sum = sum + mul * save[str[i][j] - 'A'];
				mul = mul * 10;
			}
		}
		if (sum > value)
			value = sum;
		return;
	}
	if (save[alphabet[start]] == 0) // �� �ش� ���ĺ��� ����� ���� ���� ���
	{
		for (int j = 9; j >= 0; j--)
		{
			if (visit[j] == 0) // ���ڸ� ���� �ʾ��� ���
			{
				visit[j]=1;
				save[alphabet[start]] = j; // �ش� ���ĺ��� ���� �ο�
				back(start + 1); 
				save[alphabet[start]] = 0; // �ش� ���ĺ��� ���� �ٽ� �м�
				visit[j]=0; // �湮�迭 �ʱ�ȭ
			}
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		cin >> str[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j< str[i].size() != '\0'; j++)
		{
			if (check[str[i][j] - 'A'] == 0)
			{
				check[str[i][j] - 'A'] = 1; // ���� ���ĺ� üũ
				alphabet[cnt] = str[i][j] - 'A'; // ���ĺ� ����
				cnt++; // �� ���� ���ĺ� �� üũ
			}
		}
	}
	back(0);
	printf("%d", value);
}