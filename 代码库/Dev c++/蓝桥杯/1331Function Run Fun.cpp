#include <stdio.h>
#include <string.h>
int dp[700][700][700];
int w(int a,int b,int c)
{
	if(a<=0 || b<=0 || c<=0)
	{
		dp[a][b][c]=1;
		return dp[a][b][c];
	}
	else if(a>20 || b>20 || c>20)
	{
		if(!dp[a][b][c])
			dp[a][b][c]=w(20,20,20);
		return dp[a][b][c];
	}
	else if(a<b && b<c)
	{
		if(!dp[a][b][c])
			dp[a][b][c]=w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		return dp[a][b][c];
	}
	else
	{
		if(!dp[a][b][c])
			dp[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
		return dp[a][b][c];
	}
}

int main()
{
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c),!(a==-1 && b==-1 && c==-1))
	{
		memset(dp,0,sizeof(dp));
		if(a<0)
			a=0;
		if(b<0)
			b=0;
		if(c<0)
			c=0;
		dp[a][b][c]=w(a,b,c);
		printf("w(%d, %d, %d) = %d\n",a,b,c,dp[a][b][c]);
	}	
	return 0;
}
