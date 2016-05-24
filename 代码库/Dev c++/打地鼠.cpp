#include <stdio.h>
#include <math.h>
#include <string.h>
int max(int a,int b)
{
	return a>b? a:b;
}
int min(int a,int b)
{
	return a>b? b:a;
}
int dp[25][505];
int main()
{
	int n,m;
	int i,j,k;
	int a[25][505],b;
	int index,temp;
	while(~scanf("%d %d",&n,&m))
	{
		memset(a,0,sizeof(a));
		index=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				scanf("%d",&b);
				a[i][b]=1;
				index=max(index,b);
			}
		
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=index;j++)
				dp[i][j]=1000000;
		}	
		
		for(i=1;i<=index;i++)
			if(a[1][i]==1)
				dp[1][i]=0;
		for(i=2;i<=n;i++)
		{
			for(j=1;j<=index;j++)			//这一层的位置 
			{
				if(a[i][j]==1)
					for(k=1;k<=index;k++)	//上一层的位置 
					{
						if(a[i-1][k]==1)
						{
							if(dp[i-1][k]+fabs(j-k)<dp[i][j])
							{
								dp[i][j]=dp[i-1][k]+fabs(j-k);
							}
						}
					}
			}
		}
		temp=1000000;
		for(i=1;i<=index;i++)
		{
			temp=min(temp,dp[n][i]);
		}
		printf("%d\n",temp);
		
	}
	
	return 0;
}
