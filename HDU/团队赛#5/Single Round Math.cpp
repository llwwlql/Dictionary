#include <stdio.h>
#include <string.h>
int main()
{
	int T;
	char str1[1005],str2[1005];
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s %s",str1,str2);
		if(strcmp(str1,str2)==0)
		{
			int sum=0;
			int len=strlen(str1);
			for(i=0;i<len;i++)
			{
				sum%=11;
				sum=sum*10+(str1[i]-'0');
			}
			sum%=11;
			if(sum==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
		
	}
	
	return 0;
}
