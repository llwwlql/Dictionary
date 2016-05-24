#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	int a[105];
	int i,j;
	int temp;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if((fabs(a[i])<fabs(a[j])))
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		printf("%d",a[0]);
		for(i=1;i<n;i++)
			printf(" %d",a[i]);
		putchar('\n');
	}
	
	return 0;
}
