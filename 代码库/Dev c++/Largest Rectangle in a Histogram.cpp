#include <stdio.h>
#include <string.h>
int max(int a,int b)
{
	return a>b? a:b;
}
int dp[100005];
int main()
{
	int n;
	int i,j;
	int a[100005];
	while(scanf("%d",&n),n)
	{
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
		{
			if(dp[i-1]/(i-1)>=i)
				dp[i]=max(dp[i-1],i*a[i]);
			else
				dp[i]=max(dp[i-1],(dp[i-1]/(i-1))*i);
		}
		printf("%d\n",dp[n]);
	}
	
	return 0;
}
