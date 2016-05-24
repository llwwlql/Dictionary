#include <stdio.h>
int main()
{
	int n;
	int dp[10005];
	int i,j,T;
	for(i=1;i<=10000;i++)
		dp[i]=1+(i*2+1)*i-2*i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	return 0;
}
