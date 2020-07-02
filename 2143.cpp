#include<stdio.h>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int T;
int A[1001];
int B[1001];
vector <long long int> vec;
vector <long long int> vec2;
int main()
{
	int A_index;
	int B_index;
	scanf("%d", &T);
	scanf("%d", &A_index);
	for (int i = 0; i < A_index; i++)
		scanf("%d", &A[i]);
	int A_sum = 0;
	for (int i = 0; i < A_index; i++)
	{
		A_sum = A[i];
		vec.push_back(A_sum);
		for (int j = i + 1; j < A_index; j++)
		{
			A_sum = A_sum + A[j];
			vec.push_back(A_sum);
		}
	}
	scanf("%d", &B_index);
	for (int j = 0; j < B_index; j++)
		scanf("%d", &B[j]);
	int B_sum = 0;
	for (int i = 0; i < B_index; i++)
	{
		B_sum = B[i];
		vec2.push_back(B_sum);
		for (int j = i + 1; j < B_index; j++)
		{
			B_sum = B_sum + B[j];
			vec2.push_back(B_sum);
		}
	}
	sort(vec.begin(), vec.end());
	sort(vec2.begin(), vec2.end());
	long long int result = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		int low = lower_bound(vec2.begin(), vec2.end(), T - vec[i]) - vec2.begin();
		int high = upper_bound(vec2.begin(), vec2.end(), T - vec[i]) - vec2.begin();
		result = result + high - low;
	}
	printf("%lld", result);
}