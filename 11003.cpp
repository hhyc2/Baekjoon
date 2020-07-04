#include<stdio.h>
#include<deque>
#pragma warning(disable:4996)
using namespace std;
int N;
int L;
int arr[5000001];
struct list
{
	int index;
	int value;
};
deque <list> deq;
int main() 
{
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++)
	{
		if (!deq.empty() && deq.front().index == i - L) // ºüÁú Â÷·Ê°¡ µÇ¸é »©ÁÜ 
			deq.pop_front();
		while (!deq.empty() && deq.back().value > arr[i])
			deq.pop_back();
		list temp;
		temp.index = i;
		temp.value = arr[i];
		deq.push_back(temp);
		printf("%d ", deq.front().value);
	}
}