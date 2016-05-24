#include <stdio.h>
#include <string.h>
int main()
{
	char str1[1005];
	int i;
	int a,b;
	while(~scanf("%s %d",str1,&b))
	{
		a=0;
		for(i=0;i<strlen(str1);i++)
		{
			a=a*10+str1[i]-'0';
			a=a%b;
		}
		printf("%d\n",a);
	}
	
	return 0;
}
