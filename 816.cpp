#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int r, c;
	int dir;
	Node(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir){}
};

int d[12][12][12];
Node p[12][12][12];
int hase_edge[12][12][12][12];
int r0, c0, r1, c1, r2, c2, dir;
char d0;

void init()
{
	memset(d, -1, sizeof(d));
	memset(p, 0, sizeof(p));
	memset(hase_edge, 0, sizeof(hase_edge));
}



const char* dirs = "NESW";
const char* turns = "FLR";
int dir_id(char c) { return strchr(dirs, c) - dirs;}
int turn_id(char c) { return strchr(turns, c) - turns;}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
Node walk(const Node& u, int turn)
{
	int dir = u.dir;
	if(turn == 1)dir = (dir + 3)%4;
	if(turn == 2)dir = (dir + 1)%4;
	return Node(u.r + dr[dir], u.c+dc[dir], dir);
}

bool inside(int x, int y)
{
	if(x<0||x>9||y<0||y>9)return false;
	return true;
}


void print_path(Node u)
{
	vector<Node> nodes;
	for(;;){
		nodes.push_back(u);
		if(d[u.r][u.c][u.dir]==0)break;
		u = p[u.r][u.c][u.dir];
	}
	nodes.push_back(Node(r0,  c0, dir));

	int cnt = 0;
	for (int i = nodes.size()-1; i >= 0; --i)
	{
		if(cnt % 10 == 0)printf(" ");
		printf(" (%d,%d)", nodes[i].r, nodes[i].c);
		if(++cnt% 10 == 0)printf("\n"); 
	}
	if(nodes.size()%10!=0)printf("\n");
}

void BFS()
{
	queue<Node> q;
	Node u(r1, c1, dir);
	q.push(u);
	d[r1][c1][dir] = 0;
	while(!q.empty())
	{
		Node u = q.front(); q.pop();
		if(u.r == r2 && u.c == c2){ print_path(u); return;}
		for(int i = 0; i < 3; i++)
		{
			Node v = walk(u, i);
			if(hase_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir]==-1)
			{
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	printf ("  No Solution Possible\n");
}






int main(int argc, char const *argv[])
{
	string name;
	while(cin >> name && name!="END")
	{
		init();
		cin >> r0 >> c0 >> d0 >> r2 >> c2;
		dir = dir_id(d0);
		r1 = r0 + dr[dir];
		c1 = c0 + dc[dir];


		int x, y;
		string s;

		while(cin >> x && x!=0)
		{
			cin >> y;
			while(cin >> s && s!="*")
			{
				int did = dir_id(s[0]);
				for (int i = 1; i < s.size(); ++i)
				{
					int tid = turn_id(s[i]);
					hase_edge[x][y][did][tid] = 1;
					//cout << x << " " << y << " "<<did << " " << tid <<endl;
				}	
			}
		}
		cout << name << endl;
		BFS();

	}
	return 0;
}
