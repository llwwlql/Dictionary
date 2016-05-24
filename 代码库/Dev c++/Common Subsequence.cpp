#include <stdio.h>
#include <string.h>
int dp[1005][1005];
int main()
{
	char ch1[1005],ch2[1005];
	int i,j,len1,len2;
	
	while(~scanf("%s %s",&ch1,&ch2))
	{
		len1=strlen(ch1);len2=strlen(ch2);
		memset(dp,0,sizeof(dp));
		
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(ch1[i-1]==ch2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else if(dp[i-1][j]>dp[i][j-1])
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=dp[i][j-1];
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}
