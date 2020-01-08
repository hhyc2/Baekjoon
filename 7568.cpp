#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct list
{
	int weight;
	int height;
	int grade;
};
int main()
{
	list arr[51];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &arr[i].weight, &arr[i].height);
	for (int i = 0; i < N; i++)
	{
		int grade = 1;
		for (int j = 0; j < N; j++)
		{
			if (arr[i].weight < arr[j].weight && arr[i].height < arr[j].height)
				grade++;
		}
		arr[i].grade = grade;
	}
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i].grade);
}