#include <stdio.h>
int main()
{
	int n,m;
	while(~scanf("%d %d",&m,&n))
	{
		if(m%(n+1)==0)
			printf("None\n");
		else
		{
			printf("%d",m%(n+1));
			if(n>m)
				for(int i=m%(n+1)+1;i<=n;i++)
					printf(" %d",i);
			putchar('\n');
		}
		
	}
	return 0;
}
