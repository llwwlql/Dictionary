#include <stdio.h>
double dp[105];
int main()
{
	int n,c,t,l;
	int vr,v1,v2;
	int i,j;
	int a[105];
	while(~scanf("%d",&l))
	{
		scanf("%d %d %d",&n,&c,&t);
		scanf("%d %d %d",&vr,&v1,&v2);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		a[0]=0;
		a[n+1]=l;
		dp[0]=.0;
		for(i=1;i<=n+1;i++)
		{
			dp[i]=1000000.0;
			for(j=0;j<i;j++)
			{
				int len=a[i]-a[j];
				double temp= len>=c? c*1.0/v1+(len-c)*1.0/v2 : len*1.0/v1;
				if(j)
					temp+=t;
				if(dp[i]>dp[j]+temp)
					dp[i]=dp[j]+temp; 
			}
		}
		
		double rabbit=l*1.0/vr;
		if(rabbit<dp[n+1])
			printf("Good job,rabbit!\n");
		else
			printf("What a pity rabbit!\n");
	}
	
	return 0;
}
