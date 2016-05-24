#include <stdio.h>
#include <string.h>
int dp[1005];
int w[5],v[5];
int W;
void completePack()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=w[i];j<=W;j++)
		{
			if(dp[j]<dp[j-w[i]]+v[i])
				dp[j]=dp[j-w[i]]+v[i];
		}
	}
}

int main()
{
	int T;
	int d;
	int i,ans;
	d=0;
	scanf("%d",&T);
	while(T--)
	{
		d++;
		int mark;
		double max=.0;
		ans=0;
		memset(dp,0,sizeof(dp));
		for(i=0;i<3;i++)
		{
			scanf("%d %d",w+i,v+i);
			
			if(v[i]*1.0/w[i]>max)
			{
				max=v[i]*1.0/w[i];
				mark=i;
			}
		}
			
		scanf("%d",&W);
		
		if(W<=1000)
		{
			completePack();
		}
		else
		{
			ans=(W-1000)*(v[mark]/w[mark]);
			W=1000;
			completePack();
		}
		printf("Case %d:%d\n",d,ans+dp[W]);
	}
	
	return 0;
}
