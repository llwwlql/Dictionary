#include <stdio.h>
#include <string.h>
int dp[25][25][25];
int w(int a,int b,int c)
{
	if(a<=0 || b<=0 || c<=0)
		return 1;
	else if(a>20 || b>20 || c>20)
	{
		if(dp[20][20][20]==0)
			dp[20][20][20]=w(20,20,20);
		return dp[20][20][20];
	}
	else if(a<b && b<c)
	{
		if(dp[a][b][c-1]==0)
			dp[a][b][c-1]=w(a,b,c-1);
		if(dp[a][b-1][c-1]==0)
			dp[a][b-1][c-1]=w(a,b-1,c-1);
		if(dp[a][b-1][c]==0)
			dp[a][b-1][c]=w(a,b-1,c);
		return dp[a][b][c-1]+dp[a][b-1][c-1]-dp[a][b-1][c];
	}
	else
	{
		if(dp[a-1][b][c]==0)
			dp[a-1][b][c]=w(a-1, b, c);
		if(dp[a-1][b-1][c]==0)
			dp[a-1][b-1][c]=w(a-1, b-1, c);
		if(dp[a-1][b][c-1]==0)
			dp[a-1][b][c-1]=w(a-1, b, c-1);
		if(dp[a-1][b-1][c-1]==0)
			dp[a-1][b-1][c-1]=w(a-1, b-1, c-1);
		return dp[a-1][b][c]+dp[a-1][b-1][c]+dp[a-1][b][c-1]-dp[a-1][b-1][c-1];
	}
}

int main()
{
	int n,m,p;
	memset(dp,0,sizeof(dp));
	while(scanf("%d %d %d",&n,&m,&p),n!=-1 || m!=-1 || p!=-1)
	{
		printf("w(%d, %d, %d) = %d\n",n,m,p,w(n,m,p));
	}
	
	return 0;
}
