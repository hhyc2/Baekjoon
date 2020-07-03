#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int N;
int Max[3];
int Min[3];
int main()
{
	scanf("%d", &N);
	scanf("%d %d %d", &Max[0], &Max[1], &Max[2]);
	Min[0] = Max[0];
	Min[1] = Max[1];
	Min[2] = Max[2];
	for (int i = 1; i < N; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int first_max = Max[0];
		int second_max = Max[1];
		int third_max = Max[2];
		int first_min = Min[0];
		int second_min = Min[1];
		int third_min = Min[2];
		Max[0] = max(first_max, second_max) + a;
		Max[1] = max(max(first_max, second_max), third_max) + b;
		Max[2] = max(second_max, third_max) + c;

		Min[0] = min(first_min, second_min) + a;
		Min[1] = min(min(first_min, second_min), third_min) + b;
		Min[2] = min(second_min, third_min) + c;
	}
	printf("%d ", max(max(Max[0], Max[1]), Max[2]));
	printf("%d", min(min(Min[0], Min[1]), Min[2]));
}