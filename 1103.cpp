#include <bits/stdc++.h>
using namespace std;
int H, W;
int maze[310][310];
int col[310][310];
int sum[30];
void DFS(int x, int y, int n, int c)
{
	if(x<0||x>H+1||y<0||y>4*(W+2))return;
	if(col[x][y]==-1||col[x][y]>0||maze[x][y]!=n)return;
	col[x][y]=c;
	for (int i = -1; i <= 1; ++i)
	for (int j = -1; j <= 1; ++j)
	if(abs(i)+abs(j)==1)
		DFS(x+i, y+j, n, c);
}

int main(int argc, char const *argv[])
{
	int kase = 0;
	char ch;
	int x;
	while(cin >> H >> W &&(H+W)!=0)
	{
		
		memset(maze, 0 ,sizeof(maze));
		memset(col, 0 ,sizeof(col));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= H; ++i)
		{
			for (int j = 1; j <= W; ++j)
			{
				cin >> ch;
				if(ch>='a'&&ch<='f') x = ch - 'a' + 10;
				else x = ch - '0';
				for (int k = 0; k < 4; ++k){

					maze[i][j*4+k] = (x>>(3-k)) & 1;
					
				}
				
			}
			//cout << endl;
		}

		DFS(0, 0, 0, -1);

		
		int cnt=0;
		for (int i = 1; i <= H; ++i)
		for (int j = 1; j <= 4*(W+2); ++j)
			if(maze[i][j]==1&&col[i][j]==0)
				DFS(i, j, 1, ++cnt);
				
		/*for (int i = 1; i <= H; ++i)
		{
			for (int j = 1; j <= 4*(W+2); ++j)
			{
				
				if(col[i][j]==-1)cout<<9;
				else cout <<col[i][j];
				
				
			}
			cout << endl;
		}*/
	
		for (int i = 1; i <= H; ++i)
		for (int j = 1; j <= 4*(W+2); ++j)
			if(col[i][j]==0&&col[i][j-1]!=0)
				{
					//cout <<"adsdas"<<endl;
					DFS(i, j, 0, 8);
					sum[col[i][j-1]]++;
				}
						
			

		//cout << cnt << endl;
		cout << "Case "<<++kase<<": ";
		int a,j,d,s,w,k;
		a=j=d=s=w=k=0;
		int ans=0;
		for (int i = 0; i < 30; ++i)
		{
			if(sum[i]==1)a++,ans++;
			if(sum[i]==3)j++,ans++;
			if(sum[i]==5)d++,ans++;
			if(sum[i]==4)s++,ans++;
			if(sum[i]==2)k++,ans++;
		}
		w = cnt - ans;
		for(int i = 0; i < a; i++)cout<<"A";
		for(int i = 0; i < d; i++)cout<<"D";
		for(int i = 0; i < j; i++)cout<<"J";
		for(int i = 0; i < k; i++)cout<<"K";
		for(int i = 0; i < s; i++)cout<<"S";
		for(int i = 0; i < w; i++)cout<<"W";

		cout << endl;
		/*
		for (int i = 1; i <= H; ++i)
		{
			for (int j = 1; j <= 4*(W+2); ++j)
			{
				
				if(col[i][j]==-1)cout<<9;
				else cout <<col[i][j];
				
				
			}
			cout << endl;
		}
		*/
		

	}
	return 0;
}
