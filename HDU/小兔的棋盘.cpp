#include <stdio.h>
#include <string.h>
int dp[40][40];

int main()
{
	int i,j;
	int n;
	while(scanf("%d",&n),n!=-1)
	{		
		for(i=0;i<n;i++)
		{
			dp[i][0]=1;
			dp[0][i]=1;
		}
		
		
		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(i!=j)
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
				printf("<%d %d %d>\n",i,j,dp[i][j]);
			}
		}
		dp[n-1][n-1]=dp[n-2][n-1]+dp[n-1][n-2];
		printf("%d\n",dp[n-1][n-1]);
	}
	
	return 0;
}
