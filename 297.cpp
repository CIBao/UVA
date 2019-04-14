#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
const int len = 32;
int buffer[len][len];
string s1, s2;
int cnt;
void build_tree(string s, int& p, int r, int c, int w)
{
	char ch = s[p++];
	if (ch == 'p')
	{	
		build_tree(s, p, r, c + w / 2, w / 2);
		build_tree(s, p, r, c, w / 2);
		build_tree(s, p, r + w / 2, c, w / 2);
		build_tree(s, p, r + w / 2, c + w / 2, w / 2);
	}
	else if(ch == 'f')
	{

		for (int i = r; i < r+w; i++)
		for (int j = c; j < c+w; j++)
			if (buffer[i][j] == 0)
			{
				buffer[i][j] = 1;
				cnt++;
			}
	}
}

int main()
{
	int t;
	cin >> t; 
	while (t--)
	{
		cnt = 0;
		memset(buffer, 0, sizeof(buffer));
		cin >> s1 >> s2;
		int pos = 0;
		build_tree(s1, pos, 0, 0, len);
		pos = 0;
		build_tree(s2, pos, 0, 0, len);
		printf("There are %d black pixels.\n", cnt);
	}
}
