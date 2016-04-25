#include <stdio.h>
long long dp[105][105];
int main()
{
	int i,j;
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		for(i=0;i<=n;i++)
			dp[i][0]=1;
		for(j=0;j<=m;j++)
			dp[0][j]=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				dp[i][j]=(dp[i-1][j-1]+j*dp[i-1][j])%1000000007;
		}
		printf("%I64d\n",dp[n][m]);
	}
	
	return 0;
}
