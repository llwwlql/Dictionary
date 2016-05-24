#include <stdio.h>
#include <string.h>
int dp[105];
int V,N;
void ZeroOnePack(int v,int w)
{
	for(int i=V;i>=w;i--)
	{
		if(dp[i-w]+v>dp[i])
			dp[i]=dp[i-w]+v;
	}
}

int main()
{
	int T;
	int i,j;
	int v[105],w[105],n[105];
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&V,&N);
		for(i=1;i<=N;i++)
			scanf("%d %d %d",w+i,v+i,n+i);
		for(i=1;i<=N;i++)
		{
			if(n[i]*w[i]>=V)
			{
				for(j=w[i];j<=V;j++)
				{
					if(dp[j-w[i]]+v[i]>dp[j])
						dp[j]=dp[j-w[i]]+v[i];
				}
			}
			else
			{
				int k;
				for(k=1;k<=n[i];k*=2)
				{
					ZeroOnePack(k*v[i],k*w[i]);
					n[i]-=k;
				}
				ZeroOnePack(n[i]*v[i],n[i]*w[i]);
			}
		}
		printf("%d\n",dp[V]);
	}
	
	return 0;
}
