#include<iostream>
using namespace std;
int in[100001]; // ÁÂ -> Áß -> ¿ì
int post[100001]; // ÁÂ-> ¿ì -> Áß
int idx[100001];
void find(int in_start, int in_end, int post_start, int post_end)
{
	if (in_start > in_end || post_start > post_end)
		return;
	int root = post[post_end];
	cout << root << " ";
	int temp = idx[root];
	find(in_start, temp - 1, post_start, post_start + temp-in_start-1);
	find(temp+1,in_end, post_start +temp -in_start, post_end - 1);
}
int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> in[i];
	for (int i = 0; i < num; i++)
		cin >> post[i];
	for (int i = 0; i < num; i++)
		idx[in[i]] = i;
	find(0, num - 1, 0, num - 1);
}