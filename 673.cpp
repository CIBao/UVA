#include <bits/stdc++.h>
using namespace std;

string s;

bool judge()
{
	stack<int> sk;
	for (int i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		if (c == '(' )  sk.push(1);
		else if (c == '[') sk.push(2);
		else if (c == ')') {
			if (!sk.empty() && sk.top() == 1) sk.pop();
			else return false;
		}
		else if (c == ']') {
			if (!sk.empty() && sk.top() == 2) sk.pop();
			else return false;
		}else if(c == ' ')continue;
		else return false;
	}
	if(!sk.empty())return false;
	return true;
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		getline(cin, s);
		if (judge())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
