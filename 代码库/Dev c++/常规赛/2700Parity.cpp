#include <stdio.h>
#include <string.h>
int main()
{
	int i,j;
	char str[50];
	int index,len;
	while(scanf("%s",str),str[0]!='#')
	{
		len=strlen(str);
		index=0;
		for(i=0;i<len-1;i++)
		{
			if(str[i]=='1')
				index++;
			printf("%c",str[i]);
		}
		
		if(str[len-1]=='o' && index%2==0 || str[len-1]=='e' && index%2==1)
			printf("1");
		else
			printf("0");
		putchar('\n');	
		
	}
	
	return 0;
}
