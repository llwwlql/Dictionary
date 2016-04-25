#include <stdio.h>
#include <string.h>

char str[1005];

int check()
{
	int i;
	if(str[0]>='0' && str[0]<='9')
		return 0;
	else
	{
		int len=strlen(str);
		
		for(i=0;i<len;i++)
		{
			if(!(str[i]>='0' && str[i]<='9' || str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' || str[i]=='_'))
				return 0;
		}
	}
	return 1;
}

int main()
{
	int T;

	scanf("%d%*c",&T);
	while(T--)
	{
		memset(str,0,sizeof(str));
		gets(str);
		if(check())
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
