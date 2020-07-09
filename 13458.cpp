#include<stdio.h>
#pragma warning(disable:4996)
int N;
int B, C;
int student[1000001];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &student[i]);
	scanf("%d %d", &B, &C);
	long long int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cnt++;
		int value = student[i] - B;
		if (value >= 0)
		{
			if (value % C == 0)
				cnt = cnt + value / C;
			else
				cnt = cnt + value / C + 1;
		}	
	}
	printf("%lld", cnt);
}