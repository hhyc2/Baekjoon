#include<stdio.h>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int N;
int A[4001];
int B[4001];
int C[4001];
int D[4001];
long long int cnt;
vector <int> vec;
vector <int> vec2;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int value = A[i] + B[j];
			vec.push_back(value);
			value = C[i] + D[j];
			vec2.push_back(value);
		}
	}
	sort(vec2.begin(), vec2.end());
	for (int i = 0; i < vec.size(); i++)
	{
		int low = lower_bound(vec2.begin(), vec2.end(), -vec[i] ) - vec2.begin();
		int high = upper_bound(vec2.begin(), vec2.end(), -vec[i] ) - vec2.begin();
		cnt = high - low + cnt;
	}
	printf("%lld", cnt);
}
