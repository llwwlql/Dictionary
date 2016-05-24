#include <stdio.h>
int dp[1010][5005];
int main()
{
	int i,j;
	int a[5005];
	int T,n,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&k,&n);
		for(i=n;i>=1;i--)
			scanf("%d",a+i);
		
		for(i=0;i<=k+8;i++)
		{
			for(j=0;j<=n;j++)
				dp[i][j]=32005;
		}
		
		for(j=0;j<=n;j++)
			dp[0][j]=0;
		
		for(i=1;i<=k+8;i++)
		{
			for(j=3*i;j<=n;j++)
			{
				if(dp[i][j-1]>dp[i-1][j-2]+(a[j]-a[j-1])*(a[j]-a[j-1]))
					dp[i][j]=dp[i-1][j-2]+(a[j]-a[j-1])*(a[j]-a[j-1]);
				else
					dp[i][j]=dp[i][j-1];
			}
		}
		printf("%d\n",dp[k+8][n]);
	}
	
	return 0;
}
