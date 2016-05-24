#include <stdio.h>
#include <string.h>
int main()
{
	int a[4];
	int b[4][8];
	int i,j;
	while(~scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]))
	{
		memset(b,0,sizeof(b));
		for(i=0;i<4;i++)
		{
			j=0;
			while(a[i])
			{
				b[i][j++]=a[i]%2;
				a[i]/=2;
			}
		}
		for(i=0;i<4;i++)
		{
			for(j=7;j>=0;j--)
			{
				printf("%d",b[i][j]);
			}
			putchar('.');
		}
		putchar('\n');
	}
	
	return 0;
}
