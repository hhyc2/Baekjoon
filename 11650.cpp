#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct list
{
	int x=0;
	int y=0;
};
bool compare(const list & a, const list & b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}
int main()
{
	int Test;
	list arr[100001];
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);
	sort(arr, arr + Test, compare);
	for (int i = 0; i < Test; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
}
