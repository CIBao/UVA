#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int x, y, w;
	Node(int x,int y, int w):x(x),y(y),w(w){}
};
int s1, s2, e1, e2, k;
int maze[30][30];
int mark[30][30][30];
int dis[30][30];
int n, m;

int BFS()
{
	queue<Node> Q;
	Q.push(Node(s1, s2, 0));
	mark[s1][s2][0] = 1;
	dis[s1][s2] = 0;
	while(!Q.empty())
	{
		Node node = Q.front(); Q.pop();
		if(node.x == e1 && node.y == e2)return dis[e1][e2];
		for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
		if(abs(i)+abs(j)==1){
			int dx = node.x + i;
			int dy = node.y + j;
			if(dx<0||dx>=n||dy<0||dy>=m)continue;
			if(maze[dx][dy]==0 && mark[dx][dy][0]==0){
				mark[dx][dy][0] = 1;
				dis[dx][dy] = min(dis[dx][dy], dis[node.x][node.y]+1);
				Q.push(Node(dx, dy, 0));
				
			}
			else if(maze[dx][dy] == 1 && node.w+1 <=k && mark[dx][dy][node.w + 1]==0)
			{
				mark[dx][dy][node.w + 1] = 1;
				dis[dx][dy] = min(dis[dx][dy], dis[node.x][node.y]+1);
				Q.push(Node(dx, dy, node.w+1));
			
			}
		}
	} 
	return -1;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		memset(maze, 0, sizeof(maze));
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{
				dis[i][j]=9999999;
			}
		}
		cin >> n >> m >> k;
		s1 = s2 =0;
		e1 = n-1; e2 = m-1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> maze[i][j];
			}
		}
		printf("%d\n", BFS());

	}
	return 0;
}
