#include <stdio.h>
#include <string.h>
int dp[1005][1005];
int main()
{
	int n,i,j;
	char str[1005],ch1[1005],ch2[1005];
	int a[1005],len1,len2,sum;
	while(~scanf("%d%*c",&n))
	{
		scanf("%s",str);
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			scanf("%d",&a[str[i]]);

		getchar();
		scanf("%s %s",ch1,ch2);
		printf("%s %s\n",ch1,ch2);
		
		len1=strlen(ch1);
		len2=strlen(ch2);
		
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(ch1[i-1]==ch2[j-1])
				{
					if(i==0 || j==0)
						dp[i][j]=1;
					else
						dp[i][j]=dp[i-1][j-1]+a[ch1[i-1]];
				}
				else
				{
					if(i==0 && j==0)
						dp[i][j]=0;
					else if(i==0)
						dp[i][j]=dp[i][j-1];
					else if(j==0)
						dp[i][j]=dp[i-1][j];
					else if(dp[i-1][j]>dp[i][j-1])
						dp[i][j]=dp[i-1][j];
					else
						dp[i][j]=dp[i][j-1];
				}
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}
