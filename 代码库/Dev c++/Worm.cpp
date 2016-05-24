#include <stdio.h>
#include <string.h>
int dp[105][105];
int main()
{
	int N,P,T,M;
	int i,j;
	while(~scanf("%d %d %d %d",&N,&P,&M,&T))
	{
		memset(dp,0,sizeof(dp));
		M++;
		dp[M][T]=1;
		for(i=M-1;i>=1;i--)
		{
			for(j=1;j<=N;j++)
			{
				dp[i][j]=dp[i+1][j-1]+dp[i+1][j+1];
			}
		}
		printf("%d\n",dp[1][P]);
	}
	
	return 0;
}
