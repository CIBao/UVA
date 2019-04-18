#include <bits/stdc++.h>
using namespace std;

string str;
map<long long, int> mp;
int sum;

void DFS(int depth, int s, int e)
{
	if(str[s]=='[')
	{
		int p = 0;
		for (int i = s+1; i != e; ++i)
		{
			if(str[i]=='[')p++;
			if(str[i]==']')p--;
			if(p==0&&str[i]==',')
			{
				DFS(depth+1, s+1, i-1);
				DFS(depth+1, i+1, e-1);
			}
		}
	}
	else
	{
		long long w = 0;
		for (int i = s; i <= e; ++i)
			w = w*10 + (str[i] - '0');
		sum++; mp[w<<depth]++;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		mp.clear();
		sum = 0;
		cin >> str;
		DFS(0, 0, str.size()-1);

		int maxn = 0;
		for (auto it = mp.begin(); it != mp.end(); ++it)
		{
			maxn=max(maxn, it->second);
		}
		printf("%d\n", sum-maxn);
	}
	return 0;
}
