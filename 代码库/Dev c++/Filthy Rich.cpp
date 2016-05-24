#include <stdio.h>
#include <string.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int dp[1005][1005];
int main()
{
	int T;
	int n,m;
	int i,j,k;
	scanf("%d\n",&T);
	for(k=1;k<=T;k++)
	{
		memset(dp,0,sizeof(dp));
		
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",dp[i]+j);
		
		for(i=n;i>=1;i--)
		{
			for(j=m;j>=1;j--)
			{
				dp[i][j]+=max(dp[i][j+1],max(dp[i+1][j+1],dp[i+1][j]));
			}
		}
		printf("Scenario #%d:\n%d\n\n",k,dp[1][1]);
	}
	
	return 0;
}
