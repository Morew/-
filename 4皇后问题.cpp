#include<iostream>
#include<cstring>
using namespace std;
int G[4][4];
bool vis[4][4];
bool a[20],x1[20],y1[20];
int maxn=0;
void dfs(int deep)
{
	if(deep>=4)
	{
		int cnt=0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(vis[i][j])
				{
					cnt+=G[i][j];
				}
			}
		}
		if(cnt>maxn)
		{
			maxn=cnt;
		}
	}
	for(int i=0;i<4;i++)
	{
		if(a[i]==false&&x1[i+deep]==false&&y1[i-deep+4]==false)
		{
			a[i]=true;
			x1[i+deep]=true;
			y1[i-deep+4]=true;
			vis[deep][i]=true;
			dfs(deep+1);
			vis[deep][i]=false;
			y1[i-deep+4]=false;
			x1[i+deep]=false;
			a[i]=false;
		}
	}
}
int main()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>G[i][j];
		}
	}
	memset(vis,false,sizeof(vis));
	memset(a,false,sizeof(a));
	memset(x1,false,sizeof(x1));
	memset(y1,false,sizeof(y1));
	dfs(0);
	cout<<maxn;
	return 0;
} 
