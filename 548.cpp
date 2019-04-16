#include <bits/stdc++.h>
using namespace std;
const int maxn = 10100;
int post[maxn], mid[maxn], leftt[maxn], rightt[maxn];

int n;
bool read_input(int* a)
{
	string line;
	if (!getline(cin, line)) return false;
	stringstream ss(line);
 	n = 0;
	int x;
	while(ss >> x) a[n++] = x;
	return n > 0;
	
}

int build_tree(int L1, int R1, int L2, int R2)
{
	if(L1 > R1)return 0;
	int root = post[R2];
	int p = L1;
	while(mid[p]!=root)p++;
	int cnt = p - L1;
	leftt[root] = build_tree(L1, p-1, L2, L2 + cnt - 1);
	rightt[root] = build_tree(p+1, R1, L2+cnt, R2-1);
	return root;

}

int best, minn;

void DFS(int u, int sum)
{
	sum += u;
	if(!leftt[u] && !rightt[u])
	{
		if(sum < minn ||(sum==minn && u < best))
		{
		 	minn = sum;
			best = u;
		}
	}

	if(leftt[u]) DFS(leftt[u], sum);

	if(rightt[u]) DFS(rightt[u], sum);
	
}

int main(int argc, char const *argv[])
{
	while(read_input(mid))
	{
		read_input(post);
		best = 99999999;
		minn = 99999999;
		build_tree(0, n-1, 0, n-1);
		DFS(post[n-1], 0);
		cout << best <<endl;
	}
	return 0;
}
