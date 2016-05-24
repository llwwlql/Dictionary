#include <stdio.h>
#include <string.h>
int dp[2][500005];
int main()
{
	int n;
	int i,j,p,h;
	int a,b;
	while(scanf("%d",&n),n)
	{
		memset(dp,0,sizeof(dp));
		int min,max;
		min=1000005;max=0;
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&a,&b);
			for(j=b;j<=500005;j+=b)
			{
				dp[0][j]+=a;
				if(dp[1][j]<a)
					dp[1][j]=a;
			}
		}
		
		scanf("%d %d",&p,&h);
		
		for(i=0;h>0;i++)
		{
			if(h<=p && dp[1][i]<=p)
			{
				if(i<min)
					min=i;
				if(i>max)
					max=i;
			}
			h-=dp[0][i];
			if(h<=p && h>=0)
			{
				if(i<min)
					min=i;
				if(i>max)
					max=i;
			}	
		}
		
		if(min==1000005 && max==0)
			printf("Impossible\n");
		else
			printf("%d %d\n",min,max);
	}
	
	return 0;
}
