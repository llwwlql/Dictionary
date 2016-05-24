#include <stdio.h>
#include <string.h>
int dp[1005][1005];

int main()
{
	int i,j,k;
	int T,S,D;
	int a,b,time,max,min;
	int s[1005],d[1005];
	while(~scanf("%d %d %d",&T,&S,&D))
	{
		for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
			dp[i][j]=100000;
		min=1000000;
		for(i=1;i<=T;i++)
		{
			scanf("%d %d %d",&a,&b,&time);
			if(time<dp[a][b])
			{
				dp[a][b]=time;
				dp[b][a]=time;
			}
			if(max<a)
				max=a;
			if(max<b)
				max=b;
		}
		for(k=1;k<=max;k++)
		{
			for(i=1;i<=max;i++)
			{
				for(j=1;j<=max;j++)
				{
					if(dp[i][j]>dp[i][k]+dp[k][j])
						dp[i][j]=dp[i][k]+dp[k][j];
				}
			}
		}
		
		for(i=1;i<=S;i++)
			scanf("%d",s+i);
		for(i=1;i<=D;i++)
			scanf("%d",d+i);
		for(i=1;i<=S;i++)
		{
			for(j=1;j<=D;j++)
			{
				if(min>dp[i][j])
					min=dp[i][j];
			}
		}
		printf("%d\n",min);
	}
	
	return 0;
}
