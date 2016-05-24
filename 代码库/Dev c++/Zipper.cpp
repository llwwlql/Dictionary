#include <stdio.h>
#include <string.h>
int dp[205][205];
int main()
{
	int n;
	int i,j,k;
	int len1,len2;
	char str1[205],str2[205],sum[405];
	scanf("%d%*c",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s %s %s",str1,str2,sum);
		memset(dp,0,sizeof(dp));
		len1=strlen(str1);
		len2=strlen(str2);
		
		for(j=1;j<=len1;j++)
			dp[j][0]=(str1[j-1]==sum[j-1]);
		for(k=1;k<=len2;k++)
			dp[0][k]=(str2[k-1]==sum[k-1]);
		
		for(j=1;j<=len1;j++)
		{
			for(k=1;k<=len2;k++)
			{
				dp[j][k]=(str1[j-1]==sum[j+k-1] && dp[j-1][k] || str2[k-1]==sum[j+k-1] && dp[j][k-1]);
			}
		}
		
		if(dp[len1][len2])
			printf("Data set %d: yes\n",i);
		else
			printf("Data set %d: no\n",i);
	}
	
	return 0;
}
