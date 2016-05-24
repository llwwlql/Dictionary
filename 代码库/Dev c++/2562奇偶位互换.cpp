#include <stdio.h>
#include <string.h>
int main()
{
	int T,i,j,len;
	char str[55];
	scanf("%d%*c",&T);
	while(T--)
	{
		scanf("%s",str);
		len=strlen(str);
		for(i=0;i<len;i++)
		{
			if(i%2==0)
				printf("%c",str[i+1]);
			else
				printf("%c",str[i-1]);
		}
		putchar('\n');
	}
	
	return 0;
}
