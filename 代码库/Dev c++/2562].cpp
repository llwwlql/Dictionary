#include <stdio.h>
#include <string.h>
int main()
{
	int T,len,i;
	char str[1005];
	scanf("%d%*c",&T);
	while(T--)
	{
		gets(str);
		len=strlen(str);
		for(i=0;i<len;i++)
		{
			if(str[i]=='0')
				printf("1");
			else
				printf("0");
		}
		putchar('\n');
	}
	
	return 0;
}
