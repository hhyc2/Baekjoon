#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int N;
	int M;
	int first;
	int second;
	int first_min=1001;
	int second_min=1001;
	int value = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &first, &second);
		if (first < first_min)
			first_min = first;
		if (second < second_min)
			second_min = second;
	}
	if (6 * second_min < first_min) // ³¹°³°¡ ´õ½Î¸é ÀüºÎ ³¹°³·Î »ê´Ù. 
	{
		value = value + N * second_min;
		printf("%d", value);
		return 0;
	}
	else // ³¹°³°¡ ´õ ½ÎÁö ¾Ê´Â °æ¿ì 
	{
		int num = N % 6;
		value = value + (N / 6) * first_min;
		if (num * second_min >= first_min)
			value = value + first_min;
		else
			value = value + num * second_min;
	}
	printf("%d", value);
}