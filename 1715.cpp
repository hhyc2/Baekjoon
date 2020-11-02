#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
int result;
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		pq.push(num);
	}
	for (int i = 0; i < N-1; i++)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		int sum = first + second;
		result = result + sum;
		pq.push(sum);
	}
	cout << result;
}