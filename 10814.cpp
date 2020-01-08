#include<stdio.h>
#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct list
{
	int age;
	int index;
	string name;
};
bool compare(const list & a, const list & b)
{
	if (a.age < b.age)
		return true;
	else if (a.age == b.age)
	{
		if (a.index < b.index)
			return true;
		else
			return false;
	}
		return false;
}
list arr[100000];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].age >> arr[i].name;
		arr[i].index = i;
	}
		
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++)
		cout << arr[i].age << " " << arr[i].name<< "\n";
}