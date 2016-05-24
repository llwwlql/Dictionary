#include <stdio.h>
int main()
{
	int n,m;
	int i,j,index;
	while(scanf("%d %d",&n,&m),n||m)
	{
		index=0;
		for(i=0;i<=9;i++)
		{
			for(j=0;j<=9;j++)
			{
				if((n*100+i*10+j)%m==0)
				{
					if(index==0)
					{
						printf("%d%d",i,j);
						index++;
					}
					else
						printf(" %d%d",i,j);
				}
			}
		}
		putchar('\n');
	}
	
	return 0;
}
