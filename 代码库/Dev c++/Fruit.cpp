#include <stdio.h>
#include <string.h>
int dp[105][105];

int main()
{
	int n,m;
	int i,j,k;
	int a[105][2];
	while(~scanf("%d %d",&n,&m))
	{
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				for(k=a[i][0];k<=a[i][1];k++)
				{
					if((j-k)>=0)
					{
						dp[i][j]+=dp[i-1][j-k];
						if(dp[i][j]==0)
							dp[i][j]=1;
					}
				}
			}
		}
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				printf("%d ",dp[i][j]);
			putchar('\n');
		}
		
		//printf("%d\n",dp[n][m]);
	}
	
	
	return 0;
}
