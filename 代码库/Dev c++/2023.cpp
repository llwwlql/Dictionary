#include <stdio.h>
#include <string.h>
int main()
{
	int a[100][5];
	float b[5];
	float c[100];
	int n,m,i,j,peace,index;
	while(~scanf("%d %d",&n,&m))
	{
		index=0;
		memset(b,0,sizeof(b)); 
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",a[i]+j);
				c[i]+=a[i][j];
				b[j]+=a[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			peace=1;
			for(j=0;j<m && peace;j++)
			{
				if(a[i][j]<b[j]/n)
					peace=0;
			}
			if(peace)
				index++;
		}
		printf("%.2f",c[0]/m);
		for(i=1;i<n;i++)
			printf(" %.2f",c[i]/m);
		putchar('\n');	
		printf("%.2f",b[0]/n);
		for(i=1;i<m;i++)
			printf(" %.2f",b[i]/n);
		putchar('\n');
		printf("%d\n\n",index);
	}
		
	return 0;
}
