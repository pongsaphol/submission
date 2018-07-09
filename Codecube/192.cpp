#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;


int dp[2][5010];
int mn[5010];
int a[5010];
int b[5010];

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		dp[0][i]=i;
		mn[i]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=i&1;
		dp[x][0]=1;
		for(int j=1;j<=m;j++)
		{
			dp[x][j]=(a[i]==b[j]?dp[x^1][j-1]:inf);
			dp[x][j]=min(dp[x][j],dp[x^1][j-1]+1);
			dp[x][j]=min(dp[x][j],dp[x][j-1]+1);
			dp[x][j]=min(dp[x][j],mn[j]+1);
			mn[j]=min(dp[x][j],mn[j]);
			if(dp[x][j]<=k)
			{
			  ans=max(ans,j);
			}
		}
	}
	printf("%d",ans);
	return 0;
}