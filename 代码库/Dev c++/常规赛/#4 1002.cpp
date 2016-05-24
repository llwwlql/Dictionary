#include <stdio.h>
#include <string.h>
int dp[505][505];

int main()
{
	int T,n,m;
	int i,j,peace,temp=0;
	int a[505],b[505];
	scanf("%d",&T);
	while(T--)
	{
		if(temp)
			putchar('\n');
		else
			temp=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d",b+i);
		memset(dp,0,sizeof(dp));
		peace=-1000000;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i]==b[j] && a[i]>peace)
				{
					dp[i][j]=dp[i-1][j-1]+1;
					peace=a[i];
				}
				
				else if(dp[i-1][j]>dp[i][j-1])
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=dp[i][j-1];
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
