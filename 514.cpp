#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

const int MAXN = 1100;

int A, B;
int tar[MAXN];
int n;
int main()
{
	while (cin >> n && n)
	{
		
		while (cin >> tar[1]) {
			stack<int> s;
			
			if (tar[1] == 0) {
				puts("");
				break;
			}
			
			for (int i = 2; i <= n; i++)
				cin >> tar[i];

			A = 1; B = 1;
			int ok = 1;
			while (B <= n) {
				if (A == tar[B]) {
					B++;
					A++;
				}
				else if (!s.empty() && s.top() == tar[B]) {
					s.pop(); B++;
				}
				else if (A <= n) {
					s.push(A++);
				}
				else {
					ok = 0;
					break;
				}
			}
			if (ok)puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
