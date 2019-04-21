#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 1 << 30;
const int maxn = 101000;
int res[maxn];
struct node
{
	int v, c;
	node(int v,int c):v(v),c(c){}
};
vector<node> G[maxn];
int d[maxn], inqueue[maxn];
int n, m;

void BFS(int s, int e)
{
	queue<int> Q;
	if (s == n) {
		d[s] = 0;
		Q.push(s);
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			if (x == e)break;
			for (int i = 0; i < G[x].size(); i++)
			{
				node nd = G[x][i];
				if (d[nd.v] == MX && inqueue[nd.v] == 0) {
					d[nd.v] = d[x] + 1;
					inqueue[nd.v] = 1;
					Q.push(nd.v);
				}
			}
		}
	}
	else {
		memset(inqueue, 0, sizeof(inqueue));
		Q.push(s);
		vector<int> tmp;
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			if (x == e)return;
			tmp.clear();
			tmp.push_back(x);
			while (!Q.empty())
			{
				int m = tmp[0];
				if (d[m] == d[Q.front()])
				{
					x = Q.front(); Q.pop();
					tmp.push_back(x);
				}
				else break;
			}

			int c = MX;
			for(int i = 0; i < tmp.size();i++)
			{
				int x = tmp[i];
				for (int j = 0; j < G[x].size(); j++)
				{
					node nd = G[x][j];
					if (d[x] == d[nd.v] + 1) 	c = min(c, nd.c);
				}
			}
		
			//printf("\n\n");
			//printf("c=	%d\n",  c);
			for (int i = 0; i < tmp.size(); i++) {
				int x = tmp[i];
				//printf("x=	%d\n", x);
				for (int j = 0; j < G[x].size(); j++)
				{
					node nd = G[x][j];
					//printf("v = %d  dv=%d  nc = %d\n ", nd.v, d[nd.v], nd.c);
					if (d[x] == d[nd.v] + 1 && nd.c == c)
					{
						res[d[1] - d[nd.v]] = min(res[d[1] - d[nd.v]], c);
						if (inqueue[nd.v] == 0) {
							//printf("v=	%d\n", nd.v);
							inqueue[nd.v] = 1;
							Q.push(nd.v);
						}

					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			res[i] = d[i] = MX; inqueue[i] = 0;
		}
		int x, y, z;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> z;
			G[x].push_back(node(y, z));
			G[y].push_back(node(x, z));
		}
		BFS(n, 1);
		BFS(1, n);

		cout << d[1] << endl << res[1];
		for (int i = 2; i <= d[1]; i++)
		{
			cout << " " << res[i];
		}
		cout << endl;
	}
}



