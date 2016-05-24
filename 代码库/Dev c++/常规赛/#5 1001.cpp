#include <stdio.h>
#include <string.h>
int dp[105][105];
int main()
{
	int n,p,m,t;
	int i,j;
	while(~scanf("%d %d %d %d",&n,&p,&m,&t))
	{
		memset(dp,0,sizeof(dp));
		dp[0][p]=1;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			
		}
		printf("%d\n",dp[m][t]);
	}
	
	return 0;
}
