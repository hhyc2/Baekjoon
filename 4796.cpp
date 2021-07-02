#include<iostream>
using namespace std;
int L, P, V;
int main()
{
	int index = 1;
	while (1)
	{
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			return 0;
		int value = (V / P) * L;
		if (L < V % P)
			value += L;
		else
			value += V % P;
		cout <<"Case "<<index++<<": " << value << "\n";
	}
}