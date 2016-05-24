#include <stdio.h>
int main()
{
	int i,N,n;
	long long dp[1005];
	dp[0]=dp[1]=1;
	for(i=2;i<=1000;i++)
		dp[i]=dp[i-1]+dp[i-2];
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	
	return 0;
}
