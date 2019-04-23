#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1010000;
typedef long long ll;
int n, q, cnt, c1, cnt2;

struct edge
{
	int u, v, w;
	edge(int u = 0, int v = 0, int w = 0) :u(u), v(v), w(w) {}
}e[maxn], a[1100];

int X[1100], Y[1100];
vector<int> v[10];

ll dis(int x1, int y1, int x2, int y2)
{
	int x = x1 - x2;
	int y = y1 - y2;
	return (ll)(x * x + y * y);
}

int p[1100];
bool cmp(edge e1, edge e2) { return e1.w < e2.w; }
int find(int x) { 
	//printf("%d------\n",x);
	return x == p[x] ? x : p[x] = find(p[x]); }

ll kk()
{
	ll ans = 0;
	int c1 = 0;
	for (int i = 1; i <= n; ++i) p[i] = i;
	sort(e, e + cnt, cmp);
	for (int i = 0; i < cnt; ++i)
	{
		int x = find(e[i].u);
		int y = find(e[i].v);
		if (x != y) {
			//printf("u=%d, v=%d, w=%d\n", x, y, e[i].w);
			ans += e[i].w; p[x] = y;
			a[c1++] = e[i];
		}
	}
	cnt2 = c1;
	return ans;
}

ll kk2(int s)
{
	ll ans = 0;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i <= 8; i++)
		if ((1 << i) & s) {
			ans += v[i][0];
			for (int j = 2; j < v[i].size(); j++)
			{
				int x = find(v[i][1]);
				int y = find(v[i][j]);
				if (x != y)p[x] = y;
			}
		}
	
	sort(a, a + cnt2, cmp);
	//cout << "cnt2 = " << cnt2 << endl;
	for (int i = 0; i < cnt2; ++i)
	{
		int x = find(a[i].u);
		int y = find(a[i].v);
		if (x != y) {
			//printf("u=%d, v=%d, w=%d\n", x, y, e[i].w);
			ans += a[i].w; p[x] = y;
		}
	}
	
	return ans;
}


void input()
{
	int x, y, z;
	for (int i = 0; i < 10; ++i)
		v[i].clear();
	cin >> n >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> x >> y;
		v[i].push_back(y);
		for (int j = 0; j < x; ++j)
		{
			cin >> z;
			v[i].push_back(z);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> y;
		X[i] = x, Y[i] = y;
	}

	cnt = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j)
		{
			ll w = dis(X[i], Y[i], X[j], Y[j]);
			e[cnt++] = edge(i, j, w);
			//printf("u=%d, v=%d, w=%d\n", i, j, e[cnt-1].w);
		}
}

int main(int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		input();
		ll minn = kk();		
		for (int s = 0; s < (1<<q); s++)
			minn = min(minn, kk2(s));
		cout <<  minn << endl;
		if (t)cout << endl;
	}
	return 0;
}


