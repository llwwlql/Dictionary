#include <stdio.h>
#include <string.h>
int dp[2005][2005];
int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	int n,a[405],temp;
	char str[405],ch1[2005],ch2[2005];
	int i,j,len1,len2,len;
	while(~scanf("%d%*c",&n))
	{
		scanf("%s",str);
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
			scanf("%d",&a[str[i]]);
		getchar();
		scanf("%s %s",ch1,ch2);
		len1=strlen(ch1);
		len2=strlen(ch2);
		
		for(i=0;i<=len1;i++)
			dp[i][0]=0;
		for(j=0;j<=len2;j++)
			dp[0][j]=0;
		
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(ch1[i-1]==ch2[j-1])
					dp[i][j]=dp[i-1][j-1]+a[ch1[i-1]];
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	
	return 0;
}
