#include <stdio.h>
#include <string.h>
int dp[105][105];

int max(int i,int j)
{
	int max=-1;
	if(max<dp[i-1][j-1])
		max=dp[i-1][j-1];
		
	if(max<dp[i-1][j])
		max=dp[i-1][j];
			
	if(max<dp[i-1][j+1])
		max=dp[i-1][j+1];
	else if(dp[i-1][j+1]==1)
		dp[i-1][j+1]=2;
		
	if(max<dp[i][j-1])
		max=dp[i][j-1];
	
	return max;
}

int main()
{
	int i,j;
	char a[105][105];
	int n,m,index;
	while(scanf("%d %d",&n,&m),n || m)
	{
		memset(dp,0,sizeof(dp));
		
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
				scanf("%c",a[i]+j);
		}
		
		for(i=0;i<=n;i++)
			dp[i][0]=0;
		for(i=0;i<=m;i++)
			dp[1][j]=0;
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]=='@')
					dp[i][j]=max(i,j)+1;
			}
		}
		
		index=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(dp[i][j]==1)
					index++;
			}
		}
		printf("%d\n",index);
	}
	
	return 0;
}
