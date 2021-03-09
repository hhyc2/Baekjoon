#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, K;
struct list
{
	int weight;
	int cost;
};
vector <list> vec;
vector <int> bag;
priority_queue<int> pq;
bool compare(const list& a, const list& b)
{
	if (a.weight == b.weight)
		return a.cost > b.cost;
	return a.weight < b.weight;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		list temp;
		cin >> temp.weight >> temp.cost;
		vec.push_back(temp);
	}
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		bag.push_back(num);
	}
	sort(vec.begin(), vec.end(), compare); // 
	sort(bag.begin(), bag.end()); // 무게 작은순으로 정렬
	long long int sum = 0;
	int index = 0;
	for (int i = 0; i < bag.size(); i++)
	{
		while (index < vec.size() && vec[index].weight <= bag[i])
		{
			pq.push(vec[index].cost);
			index++;
		}
		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
}