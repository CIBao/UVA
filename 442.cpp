#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int n;
int r[30], c[30];
struct matrix
{
	int n, m;
	matrix(int n, int m) :n(n), m(m){}
};
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char ch;
		cin >> ch;
		int id = ch - 'A';
		cin >> r[id] >> c[id];
	}
	string str;
	while (cin >> str)
	{
		int sum = 0;
		int flag = 1;
		stack<matrix> s;
		for (int i = 0; i < str.size(); i++)
		{
			if ('A' <= str[i] && 'Z' >= str[i]) {
				int id = str[i] - 'A';
				matrix mat(r[id], c[id]);
				s.push(mat);
			}
			else if (str[i] == ')') {
				if (s.size()>=2) {
					matrix m1 = s.top(); s.pop();
					matrix m2 = s.top(); s.pop();
					if (m2.m != m1.n) {
						//cout << m1.m << " " << m2.n << endl;
						flag = 0;
						break;
					}
					sum += m2.n * m2.m * m1.m;
					matrix mm(m2.n, m1.m);
					s.push(mm);
				}
			}
		}
		if (!flag)puts("error");
		else printf("%d\n", sum);
	}
	return 0;
}
