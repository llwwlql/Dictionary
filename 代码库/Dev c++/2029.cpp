#include <stdio.h>
#include <string.h>
int main()
{
	int i,j;
	int n,len,peace;
	char str[1005];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		len=strlen(str);
		peace=1;
		for(j=0;j<=len/2 && peace;j++)
		{
			if(str[j]!=str[len-j-1])
				peace=0;
		}
		if(peace)
			printf("yes\n");
		else
			printf("no\n");
	}
	
	return 0;
}
