#include <stdio.h>
int dp[1005][1005];
int matrix[1005][1005];
int main()
{
	int n,m;
	int i,j;
	
	while(~scanf("%d %d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				scanf("%d",matrix[i]+j);
		}
		dp[0][1]=0;
		for(i=2;i<=m;i++)
			dp[0][i]=1000000;
			
		dp[1][1]=matrix[1][1];
		
		for(i=1;i<=n;i++)
			dp[i][0]=1000000;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if((i+j)%2==0)
				{
					if(dp[i-1][j]<dp[i][j-1])
						dp[i][j]=dp[i-1][j];
					else
						dp[i][j]=dp[i][j-1];
				}
				else
				{
					if(dp[i-1][j]+(matrix[i-1][j]*matrix[i][j])<dp[i][j-1]+(matrix[i][j-1]*matrix[i][j]))
						dp[i][j]=dp[i-1][j]+(matrix[i-1][j]*matrix[i][j]);
					else
						dp[i][j]=dp[i][j-1]+(matrix[i][j-1]*matrix[i][j]);
				}
			}
		}
		

		printf("%d\n",dp[n][m]);
		
	}
	
	return 0;
}
