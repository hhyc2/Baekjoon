#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct list {
	string name;
	int index;
};
vector <list> vec;
vector <string> name;
bool compare(const list& a, const list& b)
{
	return a.name < b.name;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		list temp;
		cin >> temp.name;
		temp.index = i + 1;
		vec.push_back(temp);
		name.push_back(temp.name);
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9')
		{
			int value = 0;
			for (int j = 0; j < str.size(); j++)
			{
				value = value + (str[j] - '0');
				value = value * 10;
			}
			value = value / 10;
			cout << name[value-1] << "\n";
		}
		else
		{
			int low = 0;
			int high = N - 1;
			while (low <= high)
			{
				int mid = (low + high) / 2;
				if (vec[mid].name == str)
				{
					cout << vec[mid].index << "\n";
					break;
				}
				else if (vec[mid].name < str)
					low = mid + 1;
				else
					high = mid - 1;
			}
		}
	}
}