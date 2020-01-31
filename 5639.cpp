#include<stdio.h>
#pragma warning(disable:4996)
int tree[1000001][3];
void insert(int root, int num)
{
	if (num > root)
	{
		if (tree[root][1] == 0)
			tree[root][1] = num;
		else
			insert(tree[root][1], num);

	}
	else if (num < root)
	{
		if (tree[root][0] == 0)
			tree[root][0] = num;
		else
			insert(tree[root][0], num);
	}
}
void postorder(int start)
{
	if (tree[start][0] != 0)
		postorder(tree[start][0]);
	if (tree[start][1] != 0)
		postorder(tree[start][1]);
	printf("%d\n", start);
}
int main()
{
	int num;
	int root;
	scanf("%d", &root);
	while (scanf("%d", &num) == 1)
	{
		insert(root, num);
	}

	postorder(root);
}