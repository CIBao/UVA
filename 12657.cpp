#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 101000;

int Left[maxn], Right[maxn];
int n, m, inv, op, X, Y;

void Link(int L, int R) 
{
	Right[L] = R;
	Left[R] = L;
}

int main()
{
	int kase = 1;
	while (scanf("%d%d", &n, &m)==2)
	{
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			Left[i] = i - 1;
			Right[i] = i + 1;
			ans += i;
		}
		Right[0] = 1; Left[0] = n; Right[n] = 0; inv = 0;

		while (m--)
		{
			scanf("%d", &op);
			if (op == 4)inv = !inv;
			else
			{
				scanf("%d%d", &X, &Y);
				if (op == 3 && Right[Y] == X)swap(X, Y);
				if (op != 3 && inv == 1)op = 3 - op;
				if (op == 1 && Right[X] == Y)continue;
				if (op == 2 && Left[X] == Y)continue;
				
				int LX = Left[X], RX = Right[X];
				int LY = Left[Y], RY = Right[Y];

				if (op == 1) 
				{
					Link(LY, X); Link(X, Y); Link(LX, RX);
				}
				else if (op == 2)
				{
					Link(Y, X); Link(X, RY); Link(LX, RX);
				}
				else if(op == 3)
				{
					if (Right[X] == Y) {
						Link(LX, Y); Link(Y, X); Link(X, RY);
					}
					else {
						Link(LX, Y); Link(Y, RX); Link(LY, X); Link(X, RY);
					}
					
				}
 			}
		}
		
		long long sum = 0;
		int b = 0;
		for (int i = 1; i <= n; i++)
		{
			b = Right[b];
			if (i % 2 == 1)sum += b;
		}
		
		if (inv == 1 && n % 2 == 0)sum = ans - sum;
		printf("Case %d: %lld\n", kase++, sum);
	}
	return 0;
}
