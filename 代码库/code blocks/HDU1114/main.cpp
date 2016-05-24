#include <stdio.h>
#include <string.h>
int main()
{
	int n,T;
	int V1,V2,V;
	int i,j;
	int dp[10005],w[505],v[505];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&V1,&V2);
		V=V2-V1;
		scanf("%d",&n);
		memset(dp,1000000,sizeof(dp));
		dp[0]=0;
		for(i=1;i<=n;i++)
			scanf("%d %d",v+i,w+i);
		for(i=1;i<=n;i++)
		{
			for(j=w[i];j<=V;j++)
				if(dp[j-w[i]]+v[i]<dp[j])
					dp[j]=dp[j-w[i]]+v[i];
		}
		if(dp[V]>=1000000)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[V]);
	}

	return 0;
}
