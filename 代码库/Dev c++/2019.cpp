#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m;
	int *a;
	int i,j;
	int temp,peace;
	while(scanf("%d %d",&n,&m),n||m)
	{
		peace=1;
		a=(int *)malloc(sizeof(int)*(n+1));
		for(i=0;i<=n;i++)
		{
			scanf("%d",&temp);
		    if(peace && temp>=m)
			{
				peace=0;
				a[i++]=m;
				a[i]=temp;
			}
			else
				a[i]=temp;
		}
		printf("%d",a[0]);
		for(i=1;i<=n;i++)
			printf(" %d",a[i]);
		putchar('\n');
		free(a);
	}
	
	return 0;
}
