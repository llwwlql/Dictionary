#include <stdio.h>
#include <string.h>
int dp[25][25][25];

int w(int a,int b,int c)
{
	if(dp[a][b][c])
		return dp[a][b][c];
	if(a<=0 || b<=0 || c<=0)
	{
		dp[a][b][c]=1;
		return 1;
	}
	else if(a>20 || b>20 || c>20)
	{
		dp[a][b][c]=w(20,20,20);
		return dp[a][b][c];
	}
	else if(a<b && b<c)
	{
		dp[a][b][c]=w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		return dp[a][b][c];
	}
	else
	{
		dp[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
		return dp[a][b][c];
	}
}

int main()
{
	int a,b,c;
	int sum;
	while(scanf("%d %d %d",&a,&b,&c),!(a==-1 && b==-1 && c==-1))
	{
		sum=0;
		memset(dp,0,sizeof(dp));
		if(a<=0 || b<=0 || c<=0)
			sum=1;
		else if(a>20 || b>20 || c>20)
			sum=w(20,20,20);
		else
			sum=w(a,b,c);
		printf("w(%d, %d, %d) = %d\n",a,b,c,sum);		
	}
	
	return 0;	
}
