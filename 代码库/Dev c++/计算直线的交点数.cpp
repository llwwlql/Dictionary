#include <stdio.h>
#include <string.h>
int dp[25][200];
int main()
{
	int i,j,k;
	int n;
	memset(dp,0,sizeof(dp));
	n=20;
	dp[1][0]=1;
	dp[2][0]=dp[2][1]=1;
	for(i=3;i<=n;i++)
	{
		for(j=1;j<=i-1;j++)
		{
			for(k=0;k<=i*(i-1)/2;k++)
			{
				if(dp[i-j][k]==1)
					dp[i][k+j*(i-j)]=1;
			}
			dp[i][j*(i-j)]=1;
		}
	}
	while(~scanf("%d",&n))
	{
		printf("0");
		for(k=1;k<=n*(n-1)/2;k++)
			if(dp[n][k]==1)
				printf(" %d",k);
		putchar('\n');
	}
	
	return 0;
}
