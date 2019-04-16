#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int D, I;
		cin >> D >> I;
		int k = 1;
		for (int i = 0; i < D - 1; i++)
		{
			if (I % 2) { k = 2 * k; I = I / 2 + 1; }
			else { k = 2 * k + 1; I /= 2; }
		}
		cout << k << endl;
	}
	cin >> t;
	return 0;
}
