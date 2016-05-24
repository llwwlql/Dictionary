//大数的加法 

#include <stdio.h>
#include <string.h>
int main()
{
	int T;
	char str1[1005],str2[1005];
	int a[1005],b[1005],sum[1005];
	int i,j,len1,len2,peace,index;
	scanf("%d%*c",&T);
	for(j=1;j<=T;j++)
	{
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
		memset(sum,0,sizeof(sum));
		scanf("%s%s",str1,str2);
		len1=strlen(str1);
		len2=strlen(str2);
		memset(a,0,1000);
		memset(b,0,1000);
		for(i=0;i<len1;i++)
			a[i]=str1[len1-i-1]-'0';
		for(i=0;i<len2;i++)
			b[i]=str2[len2-i-1]-'0';
		peace=0;
		index=0;
		for(i=0;i<len1;i++)
		{
			sum[i]=(a[i]+b[i]+peace)%10;
			peace=(a[i]+b[i]+peace)/10;
			index++;
		}
				
		for(i=len1;i<len2;i++)
		{
			sum[i]=(a[i]+b[i]+peace)%10;
			peace=(a[i]+b[i]+peace)/10;
			index++;
		}
		if(peace)
		{
			sum[index]+=peace;
			index++;
		}
		printf("Case %d:\n",j);
		printf("%s + %s = ",str1,str2);
		for(i=index-1;i>=0;i--)
			printf("%d",sum[i]);
		putchar('\n');
		if(j!=T)
			putchar('\n');
	}
	
	return 0;
}
