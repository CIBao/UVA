#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 1010000;

string s;
int nt[maxn];
int last, cur;

int main(int argc, char const *argv[])
{
	while(cin >> s)
	{
		memset(nt, 0 ,sizeof(nt));
		s = " "+s;
		cur = last = 0;
		nt[cur] = 0;
		for (int i = 1; i <= s.size()-1; ++i)
		{
			if(s[i] == '[')cur = 0;
			else if(s[i] == ']')cur = last;
			else{
				nt[i] = nt[cur];
				nt[cur] = i;
				if(cur == last)last=i;
				cur = i;
			}
		}

		for(int i = nt[0]; i != 0; i = nt[i])
			if(s[i]!='[' && s[i]!=']')
				cout<<s[i];
		printf("\n");
	}
	return 0;
}
