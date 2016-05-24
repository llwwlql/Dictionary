#include <stdio.h>
#include <string.h>
int f(int a,int b)
{
	return (a-b)*(a-b);
}

int dp[1005][2005];
int main()
{
	int i,j;
	int n,k;
	int a[2005],temp;
	while(~scanf("%d %d",&n,&k))
	{
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		memset(dp,0,sizeof(dp));
		for(i=1;i<=k;i++)
		{
			dp[i][2*i]=dp[i-1][2*i-2]+f(a[2*i-1],a[2*i]);
			for(j=i*2+1;j<=n;j++)
			{
				if(dp[i-1][j-2]+f(a[j-1],a[j])<dp[i][j-1])
					dp[i][j]=dp[i-1][j-2]+f(a[j-1],a[j]);
				else
					dp[i][j]=dp[i][j-1];
			}
		}
		printf("%d\n",dp[k][n]);
	}
	
	return 0;
}
