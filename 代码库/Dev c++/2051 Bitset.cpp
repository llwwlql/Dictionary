#include <stdio.h>
int main()
{
	int n;
	int a[15],i;
	while(~scanf("%d",&n))
	{
		for(i=0;n;i++)
		{
			a[i]=n%2;
			n/=2;
		}
		for(i=i-1;i>=0;i--)
			printf("%d",a[i]);
		putchar('\n');
	}
	
	return 0;
}
