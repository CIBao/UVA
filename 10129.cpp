#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int G[30][30];
int in[30], out[30], vis[30];

void DFS(int u)
{
	vis[u] = 0;
	for (int i = 0; i < 26; ++i)
		if ((G[u][i] || G[i][u]) && vis[i])
			DFS(i);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(G, 0, sizeof(G));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(vis, 0, sizeof(vis));
		cin >> n;
		int start;
		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			int x1 = s[0] - 'a';
			int x2 = s[s.size() - 1] - 'a';
			G[x1][x2]++;
			out[x1]++; in[x2]++;
			vis[x1] = vis[x2] = 1;
			start = x1;
		}

		int flag = 0;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < 26; ++i)
		{
			int x = in[i] - out[i];
			if (x == 1) cnt1++;
			else if (x == -1)cnt2++;
			else if (x != 0) flag = 1;
		}

		if (flag == 0)
		{
			if (cnt1 + cnt2 == 0 || (cnt1 == 1 && cnt2 == 1))
			{
				DFS(start);
				int cnt = 0;
				for (int i = 0; i < 26; ++i)
				{
					cnt += vis[i];
				}
				if (cnt != 0)flag = 1;
			}
			else flag = 1;
		}

		if (flag == 1)printf("The door cannot be opened.\n");
		else printf("Ordering is possible.\n");
	}
	return 0;
}
