#include <stdio.h>
#include <string.h>
int dp[105][105];
int main()
{
	int n,m;
	int i,j,k;
	int a[105][105];
	while(scanf("%d %d",&n,&m),n||m)
	{
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",a[i]+j);
		for(i=1;i<=n;i++)				//�ڼ��ſ� 
		{
			for(j=1;j<=m;j++)			//j��֮ǰ������ֵ 
			{
				for(k=1;k<=m;k++)		//����k��ļ�ֵ 
				{
					if(j>=k)
					{
						if(dp[i-1][j-k]+a[i][k]>dp[i][j])
							dp[i][j]=dp[i-1][j]+a[i][k];
						else if(k==1)
							dp[i][j]=dp[i-1][j];
					}
					else if(k==1)
						dp[i][j]=dp[i-1][j];
				}
			}
		}
		
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
