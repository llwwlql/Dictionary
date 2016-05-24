#include <stdio.h>
#include <string.h>
int dp[35005];
int main()
{
	int N;
	int i,j;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(i=1;i<=3;i++)
	{
		for(j=i;j<=35000;j++)
			dp[j]+=dp[j-i];
	}
	
	while(~scanf("%d",&N))
		printf("%d\n",dp[N]);
	
	return 0;
}
