#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int n,T;
	int i,j;
	int a[505];
	scanf("%d",&T);
	while(T--)
	{
		int min=0;
		scanf("%d",&n);
		int temp=n/2;
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		qsort(a,n,sizeof(a[0]),cmp);
		
		for(i=0;i<n;i++)
		{
			min+=fabs(a[temp]-a[i]);
		}
		printf("%d\n",min);
	}
	
	return 0;
}
