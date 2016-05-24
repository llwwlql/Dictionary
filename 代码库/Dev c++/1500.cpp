#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[1010][5005];
int f(int x)
{
	return x*x;
}

int main()
{
	int T,k,n;
	int i,j;
	int a[5005];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&k,&n);
		memset(dp,0,sizeof(dp));
		k=k+8;
		for(i=n;i>=1;i--)
			scanf("%d",a+i);
		for(i=1;i<=k;i++)
		{
			dp[i][i*3]=dp[i-1][i*3-2]+f(a[3*i-1]-a[3*i]);
			for(j=3*i+1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j-1],dp[i-1][j-2]+f(a[j-1]-a[j]));
			}
		}
		printf("%d\n",dp[k][n]);
	}
	
	return 0;
}
