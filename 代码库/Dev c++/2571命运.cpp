#include <stdio.h>
#include <string.h>
int map[25][1005];

int MAX(int a,int b)
{
	return a>b? a:b;
}

int main()
{
	int T;
	int n,m;
	int dp[25][1005];
	int i,j,k;
	scanf("%d",&T);
	while(T--)
	{
		int max;
		memset(map,0,sizeof(map));
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",map[i]+j);
		 for(i=0;i<m;i++)
            dp[0][i]=-105;
        for(i=0;i<n;i++)
            dp[i][0]=-105;
            
    	dp[0][1]=dp[1][0]=0;
    	
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				max=MAX(dp[i-1][j],dp[i][j-1]);
				for(k=2;k<=m;k++)
				{
					if(j%k==0)
						max=MAX(max,dp[i][j/k]);
				}
				dp[i][j]=max+map[i][j];				
			}
		}
		
		printf("%d\n",dp[n][m]);
	}
	
	return 0;
}
