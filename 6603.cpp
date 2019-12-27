#include<stdio.h>
#pragma warning(disable:4996)
int lotto[7];
int arr[14];
void find(int start, int depth, int N)
{
	if (depth == 6) {                    //≈ª√‚¡∂∞«
		for (int i = 0; i < 6; i++) {
			printf("%d ", lotto[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < N; i++) {   
		lotto[depth] = arr[i];      
		find(i + 1, depth + 1, N);
	}
}
int main()
{
	while (1)
	{
		int N;
		scanf("%d", &N);
		if (N == 0)
			return 0;
		else
		{
			for (int i = 0; i < N; i++)
				scanf("%d", &arr[i]);
			find(0,0,N);
			printf("\n");
		}
	}
}

