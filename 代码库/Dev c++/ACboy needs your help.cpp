#include <stdio.h>
#include <string.h>
int dp[105];
int main()
{
	int n,m;
	int i,j,k;
	int a[105][105];
	while(scanf("%d %d",&n,&m),n||m)
	{
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",a[i]+j);
		for(i=1;i<=n;i++)
		{
			for(j=m;j>=1;j--)
			{
				for(k=1;k<=m;k++) 
				{
					if(j>=a[i][k])
					{
						if(dp[j-k]+a[i][k]>dp[j])
							dp[j]=dp[j-k]+a[i][k];
					}
				}
			}
		}
		printf("%d\n",dp[m]);
	}
	return 0;
}
