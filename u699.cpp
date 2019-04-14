#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 101000;
int sum[maxn];

void build(int p)
{
	int x;
	cin >> x;
	if (x == -1)return;
	sum[p] += x;
	build(p - 1);
	build(p + 1);
}

bool init()
{
	memset(sum, 0, sizeof(sum));
	int pos = maxn / 2;
	int x;
	cin >> x;
	if (x == -1)return false;
	sum[pos] += x;
	build(pos - 1);
	build(pos + 1);
	return true;
}
int main()
{
	int kase = 0;
	while (init())
	{
		int p = 0;
		while (!sum[p]) p++;
		printf("Case %d:\n%d", ++kase, sum[p++]);
		while (sum[p])
		{
			printf(" %d", sum[p++]);
		}
		printf("\n\n");
	}
	return 0;
}
