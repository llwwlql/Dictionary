#include <stdio.h>
#include <string.h>
int main()
{
	int T;
	int i,len;
	char str1[55],str2[55];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s %s",str1,str2);
		len=strlen(str1);
		for(i=0;i<len/2;i++)
			printf("%c",str1[i]);
		printf("%s",str2);
		for(i=len/2;i<len;i++)
			printf("%c",str1[i]);
		putchar('\n');
	}
	
	return 0;
}
