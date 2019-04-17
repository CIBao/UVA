#include <bits/stdc++.h>
using namespace std;

int G[110][110];
int c[110], topo[110];
int n, m, t;

bool dfs(int u)
{
	c[u] = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (G[u][i]) {
			if (c[i] < 0)return false;
			else if (!c[i] && !dfs(i)) return false;
		}
	}
	c[u] = 1; topo[--t] = u;
	return true;
}

bool toposort()
{
	t = n;
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; ++i)
	{
		if (!c[i]) {
			if (!dfs(i))return false;
		}
	}
	return true;
}
int main()
{
	while (cin >> n >> m && (n + m) != 0)
	{
		memset(G, 0, sizeof(G));
		int x, y;
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y;
			G[x][y] = 1;
		}
		if (toposort())
		{
			cout << topo[0];
			for (int i = 1; i < n; ++i)
			{
				cout << " " << topo[i];
			}
			cout << endl;
		}
	}
}
