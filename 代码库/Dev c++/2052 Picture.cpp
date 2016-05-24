#include <stdio.h>
int main()
{
	int n,m;
	int i,j;
	while(~scanf("%d %d",&n,&m))
	{
		printf("+");
		for(i=0;i<n;i++)
			printf("-");
		printf("+\n");
		for(i=0;i<m;i++)
		{
			putchar('|');
			for(j=0;j<n;j++)
				putchar(' ');
			printf("|\n");
		}
		printf("+");
		for(i=0;i<n;i++)
			printf("-");
		printf("+\n\n");
	}
	return 0;
}
