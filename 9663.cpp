#include<stdio.h>
#pragma warning(disable:4996)
int chess[16];
int count;
int flag;
void BackTracking(int row, int N)
{
	if (row == N)
	{
		count++;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			flag = 0;
			chess[row] = i;
			for (int j = 0; j < row; j++)
			{
				int num = chess[row] - chess[j];
				if (num < 0)
					num = num * -1; // 대각선 체크 
				if(chess[row] == chess[j] || (row - j) == num) // 세로, 대각선 체크
					flag = 1;
			}
			if (flag == 0)
				BackTracking(row + 1, N);
		}
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	BackTracking(0,N);
	printf("%d", count);
}
