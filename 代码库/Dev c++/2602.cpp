#include <stdio.h>
#include <string.h>
int dp[1005];
int main()
{
	int T,n;
	int i,j;
	int w[1005],v[1005],V;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&V);
		for(i=1;i<=n;i++)
			scanf("%d",v+i);
		for(j=1;j<=n;j++)
			scanf("%d",w+j);
		for(i=1;i<=n;i++)
		{
			for(j=V;j>=w[i];j--)
			{
				if(dp[j]<dp[j-w[i]]+v[i])
					dp[j]=dp[j-w[i]]+v[i];
			}
		}
		printf("%d\n",dp[V]);
	}
	
	return 0;
}
