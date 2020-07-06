#include<stdio.h>
#include<memory.h>
#pragma warning(disable:4996)
int N;
char phone_number[10001][11];
struct list
{
	list* arr[10];
	bool check = false;
	void insert(char * key)
	{
		if (*key == '\0')
			check = true;
		else
		{
			int index = *key - '0';
			if (arr[index] == NULL)
				arr[index] = new list();
			arr[index]->insert(key + 1);
		}
	}
	bool find(char* key)
	{
		if (*key == '\0')
			return false;
		if (check == true)
			return true;
		int index = *key - '0';
		return arr[index]->find(key + 1);
	}
};
int main()
{
	int Test;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d", &N);
		list* root = new list();
		bool flag = false;
		for (int j = 0; j < N; j++)
			scanf("%s", &phone_number[j]);
		for (int j = 0; j < N; j++)
			root->insert(phone_number[j]);
		for (int j = 0; j < N; j++)
		{
			if (root->find(phone_number[j]))
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
			printf("NO\n");
		else
			printf("YES\n");
	}
}