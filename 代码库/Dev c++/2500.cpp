#include <stdio.h>
int main()
{
	int T,n,i,j;
	char str[4]="HDU";
	str[3]='\0';
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n*3;i++)
		{
			for(j=1;j<=n;j++)
				printf("%s",str);
			putchar('\n');
		}
	}
	
	return 0;
}
