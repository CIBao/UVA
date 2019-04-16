#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
const int maxn = 1010;
using namespace std;
bool fail;
char s[maxn];

struct Node
{
	bool have_val;
	int v;
	Node* left;
	Node* right;
	Node() :have_val(false), left(NULL), right(NULL) {}
};

Node* root;

Node* newnode()
{
	return new Node();
}

void removeTree(Node* u)
{
	if (u == NULL)return;
	removeTree(u->left);
	removeTree(u->right);
	delete u;
}

void addnode(int v, char* s)
{
	int n = strlen(s);
	Node* u = root;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L') {
			if (u->left == NULL)u->left = newnode();
			u = u->left;
		}
		if (s[i] == 'R') {
			if (u->right == NULL)u->right = newnode();
			u = u->right;
		}
	}
	if (u->have_val)fail = true;
	u->v = v;
	u->have_val = true;
}

bool read_input()
{
	removeTree(root);
	root = newnode();
	fail = false;
	for (;;) {
		if (scanf("%s", s) != 1)return false;
		if (!strcmp(s, "()"))break;
		int v;
		sscanf(&s[1], "%d", &v);
		//cout<<v<<" "<< strchr(s, ',') + 1 << endl;
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}

vector<int> vec;
void BFS(vector<int>& vec)
{
	vec.clear();
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		//cout << "xxx" << endl;
		Node* nd = q.front(); q.pop();
		if (!nd->have_val)
		{
			fail = true;
			return;
		}
		//cout << "SSS" << endl;
		vec.push_back(nd->v);
		if (nd->left != NULL)q.push(nd->left);
		if (nd->right != NULL)q.push(nd->right);
	}
}

int main()
{
	while (read_input())
	{
		BFS(vec);
		if (fail)printf("not complete\n");
		//cout << vec.size() << endl;
		else 
		{
			printf("%d", vec[0]);
			for (int i = 1; i < vec.size(); i++)
			{
				printf(" %d", vec[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
