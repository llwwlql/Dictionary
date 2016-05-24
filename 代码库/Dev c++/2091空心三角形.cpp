#include <stdio.h>
int main()
{
	char ch;
	int i,j,n;
	int peace=1;
	while(ch=getchar(),ch!='@')
	{
		scanf("%d%*c",&n);
		if(peace)
			peace=0;
		else
			putchar('\n');
		if(n==1)
			printf("%c\n",ch);
		else
		{
			for(i=1;i<n;i++)
			{
				for(j=1;j<=n-i;j++)
					putchar(' ');
				putchar(ch);
				for(j=1;j<=(i-1)*2-1;j++)
					putchar(' ');
				if(i!=1)
					putchar(ch);
				putchar('\n');					
			}
			for(i=1;i<=2*n-1;i++)
				putchar(ch);	
			putchar('\n');
		}
	}
	
	return 0;
}
