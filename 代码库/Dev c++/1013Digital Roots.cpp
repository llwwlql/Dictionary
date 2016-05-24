#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n,temp;
	int i,len;
	char str[1005];
	while(scanf("%s",&str),str[0]!='0')
	{
		len=strlen(str);
		temp=0;
		for(i=0;i<len;i++)
			temp+=str[i]-'0';
		while(temp>=10)
		{
			memset(str,0,sizeof(str));
			sprintf(str,"%d",temp);
			len=strlen(str);
			temp=0;
			for(i=0;i<len;i++)			
				temp+=str[i]-'0';
		}
		
		printf("%d\n",temp);
	}
	
	return 0;
}
