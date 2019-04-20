#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>

using namespace std;

const int maxn = 1100;
int n;
vector<int> bfs, dfs;
int pos[maxn];
set<int> son[maxn];

void init()
{
	bfs.clear(); dfs.clear();
	int a;
	for (int i = 0; i <= n; i++)	son[i].clear();
	for (int i = 0; i < n; i++) {
		cin >> a, bfs.push_back(a);
		pos[a] = i;
	}
	for (int i = 0; i < n; i++)	cin >> a, dfs.push_back(a);
}

int main()
{
	while (cin >> n)
	{
		init();
		
		stack<int> s;
		int rt = dfs[0];
		s.push(rt);
		for (int i = 1; i < n; i++)
		{
			while (1) {
				int cur = dfs[i];
				int fa = s.top();
				if (fa == rt || pos[fa] + 1 < pos[cur])
				{
					son[fa].insert(cur);
					s.push(cur);
					break;
				}
				else s.pop();
			}
		}

		set<int>::iterator it;
		for (int i = 1; i <= n; ++i)
		{
			cout << i << ":";
			for (it = son[i].begin(); it != son[i].end(); ++it)
				cout << ' ' << *it;
			cout << '\n';
		}
	}
	return 0;
}
