#include <bits/stdc++.h>
using namespace std;
const int maxn = 50100;
const int inf = 1<<30;
int r[maxn], u[maxn], v[maxn], w[maxn];
int p[maxn];
int n, m;

void init()
{
	memset(r, 0, sizeof(r));
	memset(u, 0, sizeof(u));
	memset(v, 0, sizeof(v));
	memset(w, 0, sizeof(w));
	memset(p, 0, sizeof(p));
}

bool cmp(int x, int y)
{
	return w[x] < w[y];
}

int find(int x)
{
	return p[x] == x ? p[x] : p[x] = find(p[x]);
}

int KK(int L)
{
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	int ans = 0;
	for (int i = L; i < m; ++i)
	{
		int e = r[i];
		int x = find(u[e]);
		int y = find(v[e]);
		if (x != y)
		{
			p[x] = y; ans++;
		}

		if (ans == n - 1)return w[e] - w[r[L]];
	}
	return inf;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m && (n + m) != 0)
	{
		init();
		for (int i = 0; i < m; ++i)
			cin >> u[i] >> v[i] >> w[i];
		for (int i = 0; i < m; ++i)
			r[i] = i;
		sort(r, r + m, cmp);
		int minn = inf;
		for (int i = 0; i < m; ++i)
		{
			minn = min(minn, KK(i));
		}
		if(minn == inf)minn = -1;
		printf("%d\n", minn);
	}
	return 0;
}
