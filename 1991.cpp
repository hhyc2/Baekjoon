#include<stdio.h>
#pragma warning(disable:4996)
char tree[30][3];
void preorder(int start)
{
	printf("%c", start + 'A');
	if (tree[start][0] != '.')
		preorder(tree[start][0] - 'A');
	if (tree[start][1] != '.')
		preorder(tree[start][1] - 'A');
}
void inorder(int start)
{
	if (tree[start][0] != '.')
		inorder(tree[start][0] - 'A');
	printf("%c", start + 'A');
	if (tree[start][1] != '.')
		inorder(tree[start][1] - 'A');
}
void postorder(int start)
{
	if (tree[start][0] != '.')
		postorder(tree[start][0] - 'A');
	if (tree[start][1] != '.')
		postorder(tree[start][1] - 'A');
	printf("%c", start + 'A');
}
int main()
{
	int Test;
	char x;
	scanf("%d%c", &Test,&x);
	char c;
	char left;
	char right;
	for (int i = 0; i < Test; i++)
	{
		scanf("%c %c %c%c", &c, &left, &right, &x);
		tree[c - 'A'][0] = left;
		tree[c - 'A'][1] = right;
	}
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
}