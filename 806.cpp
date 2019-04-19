#include <bits/stdc++.h>
using namespace std;
const int maxn = 64;
int n;
int G[maxn][maxn];
vector<int> v;
int black_num;

int judge_full(int x, int y, int w)
{
	int sum = 0;
	for (int i = x; i < x + w; ++i)
		for (int j = y; j < y + w; ++j)
			sum += G[i][j];

	if (sum == w * w)return 1; //black
	if (sum == 0)return 2; //white
	return 0;
}

int toConvert10(string s)
{
	if (s == "")return 0;
	int sum = 0;
	for (int i = 0; i != s.size(); ++i)
		sum = sum * 5 + (s[i] - '0');
	return sum;
}


void solve(int x, int y, int w, string s)
{
	int ans = judge_full(x, y, w);
	if (ans == 1) {
		int m = toConvert10(s); v.push_back(m);
		return;
	}
	if (ans == 2)return;
	solve(x, y, w / 2,   "1" + s);
	solve(x, y + w / 2, w / 2, "2" + s);
	solve(x + w / 2, y , w / 2, "3" + s);
	solve(x + w / 2, y + w / 2, w / 2, "4" + s);
}

string toConvert5(int x)
{
	string ans = "";
	while (x > 0)
	{
		char c = (x % 5) + '0';
		ans = ans + c;
		x /= 5;
	}
	return ans;
}

void draw(int x, int y, int w, string s)
{
	for (int i = 0; i < s.size(); ++i)
	{

		char c = s[i];
		if (c == '1') {x = x; y = y;}
		if (c == '2') {x = x; y = y + w / 2;}
		if (c == '3') {x = x + w / 2; y = y;}
		if (c == '4') {x = x + w / 2; y = y + w / 2;}
		w /= 2;
	}

	//cout << x << " " << y << " " << w << " " << s << endl;
	for (int i = x; i < x + w; ++i)
	{
		for (int j = y; j < y + w; ++j)
		{
			G[i][j] = 1;
		}
	}
}

void solve2()
{
	if (v.size() == 0)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				G[i][j] = 0;
	else if (v[0] == 0)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				G[i][j] = 1;
	else {
		for (int i = 0; i < v.size(); ++i)
		{
			string str = toConvert5(v[i]);	
			draw(0, 0, n, str);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (G[i][j] == 0)cout << ".";
			else cout << "*";
		}
		cout << endl;
	}
}

void input()
{
	getchar();
	int x;
	string line;
	while (true)
	{
		getline(cin, line);
		stringstream ss(line);
		while (ss >> x)
			if (x != -1)
				v.push_back(x);
			else return;
	}
}
int main(int argc, char const *argv[])
{
	int kase = 0;
	char x;
	int flag = 0;
	while (cin >> n && n)
	{
		if(flag)printf("\n");
		flag = 1;
		v.clear();
		if (n > 0)
		{
			black_num = 0;

			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
				{
					cin >> x;
					G[i][j] = x - '0';
				}
			solve(0, 0, n, "");
			sort(v.begin(), v.end());
			printf("Image %d\n", ++kase);
			int cnt = 0;
			for (int i = 0; i < v.size(); ++i) {
				if (i % 12 == 0)cout << v[i];
				else cout << " " << v[i];
				if (++cnt % 12 == 0)cout << endl;
			}
			if (v.size() % 12 != 0)cout << endl;
			printf("Total number of black nodes = %d\n", v.size());
		}
		else
		{
			n = -n;
			input();
			printf("Image %d\n", ++kase);
			solve2();
		}
	}
	return 0;
}
