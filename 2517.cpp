#include<stdio.h>
#include<math.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int N;
int seg[1 << 21];
struct list
{
	int score; // ���
	int grade; // �ε��� 
};
bool compare(const list& a, const list& b)
{
	return a.score < b.score;
}
bool compare2(const list& a, const list& b)
{
	return a.grade < b.grade;
}
int query(int node, int s, int e, int left, int right)
{
	int mid = (s + e) / 2;
	if (left <= s && e <= right)
		return seg[node];
	if (s > right || e < left)
		return 0;
	return query(node * 2, s, mid, left, right) + query(node * 2 + 1, mid + 1, e, left, right);
}
list arr[500001];
int main()
{
	scanf("%d", &N);
	int sz = pow(2, (int)log2(N - 1) + 1);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i].score);
		arr[i].grade = i;
	}
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++)
		arr[i].score = i; // ���� 
	sort(arr, arr + N, compare2); // �ε��� ������ �ٽ� ����
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", query(1, 0, sz - 1, arr[i].score, N - 1) +1 ); 
		for (int j = sz + arr[i].score; j > 0; j = j / 2) // ������Ʈ 
			seg[j]++;
	}
}