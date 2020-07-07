#include<iostream>
#include<stdio.h>
#include<string>
#pragma warning(disable:4996)
using namespace std;
int total_count;
char ar[31];
struct list
{
	list * arr[128];
	bool check = false;
	int cnt = 0;
	void insert(char * key)
	{
		if (*key == '\0')
		{
			check = true;
			cnt++;
		}
		else
		{
			if (arr[*key] == NULL)
				arr[*key] = new list();
			arr[*key]->insert(key + 1);
		}
	}
	void search(int index)
	{
		if (check == true)
		{
			for (int j = 0; j < index; j++)
				printf("%c", ar[j]);
			double value = (double)cnt / total_count *100;
			printf(" %0.4lf\n", value);
		}
		for (int i = 0; i < 128; i++)
		{
			if (arr[i] != NULL)
			{
				ar[index] = i;
				arr[i]->search(index+1);
			}
		}
	}
};
int main()
{
	string str;
	list * root = new list();
	while (getline(cin, str))
	{
		root->insert(&str[0]);
		total_count++;
	}
	root->search(0);
}