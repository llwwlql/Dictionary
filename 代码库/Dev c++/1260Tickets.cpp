#include <stdio.h>
int main()
{
	int n;
	int T,i,j;
	int a[2005],b[2005],dp[2005];
	char sh[3]="am";
	scanf("%d",&T);
	while(T--)
	{
		int h,m,s;
		h=8;
		s=m=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=2;i<=n;i++)
			scanf("%d",b+i);
		dp[0]=0;
		dp[1]=a[1];
		for(i=2;i<=n;i++)
		{
			if(dp[i-1]+a[i]<dp[i-2]+b[i])
				dp[i]=dp[i-1]+a[i];
			else
				dp[i]=dp[i-2]+b[i];
		}
		
		s=dp[n]%60;
		m=dp[n]/60;
		h=h+m/60;
		m%=60;
		h%=24;
		if(h>12)
		{
			sh[0]='p';
			h-=12;
		}
		else
			sh[0]='a';
		printf("%02d:%02d:%02d %s\n",h,m,s,sh);
	}
	
	return 0;
}
