#include<iostream>
#include<vector>
using namespace std;
struct list
{
	string str;
	int num;
};
vector<list>vec;
int main()
{
	int Test;
	cin >> Test;
	for (int i = 0; i < Test; i++)
	{
		int num;
		cin >> num;
		int answer = 1;
		for (int j = 0; j < num; j++)
		{
			string name;
			string wear;
			cin >> name >> wear;
			int flag = 0;
			for (int i = 0; i < vec.size(); i++)
			{
				if (vec[i].str == wear)
				{
					flag = 1;
					vec[i].num++;
				}
			}
			if (flag == 0)
			{
				list temp;
				temp.str = wear;
				temp.num = 1;
				vec.push_back(temp);
			}
		}
		for (int i = 0; i < vec.size(); i++)
			answer *= vec[i].num+1;
		cout << answer - 1 << "\n";
		vec.clear();
	}
}