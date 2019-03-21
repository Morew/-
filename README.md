# -采药
动态规划
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T,M;
	int i,j;
	scanf("%d%d",&T,&M);
	int t[1005],w[1005],b[105][1000]={0};
	for(i=1;i<=M;i++){
		scanf("%d%d",&t[i],&w[i]);
	}
	for(i=1;i<=M;i++){
		for(j=T;j>=0;j--){//时间 
			if(t[i]>j)
			{
				b[i][j]=b[i-1][j];
			}
			else
			{
                b[i][j]=max(b[i-1][j],b[i-1][j-t[i]]+w[i]);
			}
		}
	}
	printf("%d",b[M][T]);
}
