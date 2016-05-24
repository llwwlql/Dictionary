#include <stdio.h>
int main()
{
	int dp[35],i,j;
	int T,n;
	dp[1]=1;
	dp[2]=3;
	for(i=3;i<=30;i++)
		dp[i]=dp[i-2]*3+dp[i-1];
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	
	return 0;
}
