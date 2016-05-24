#include <stdio.h>
int dp[105][105];

int main()
{
	int a[105][105];
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
			scanf("%d",a[i]+j);
	}
	
	for(j=1;j<=n;j++)
		dp[n][j]=a[n][j];
	
	for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			if(dp[i+1][j]>dp[i+1][j+1])
				dp[i][j]=dp[i+1][j]+a[i][j];
			else
				dp[i][j]=dp[i+1][j+1]+a[i][j];
		}
	}
	printf("%d\n",dp[1][1]);
	
	return 0;
}
