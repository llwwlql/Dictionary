#include <stdio.h>
int main()
{
	int a[35];
	int n;
	int i,j;
	while(~scanf("%d",&n))
	{
		a[0]=a[1]=1;
		if(n>0)
			printf("%d\n",a[0]);
		if(n>1)
			printf("%d %d\n",a[0],a[1]);
		for(i=2;i<n;i++)
		{
			a[i]=1;
			for(j=i-1;j>0;j--)
				a[j]=a[j]+a[j-1];
			for(j=0;j<=i;j++)
				printf("%d%c",a[j],j==i? '\n':' ');
		}
		putchar('\n');
	}
	
	return 0;
}
