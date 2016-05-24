#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int n,k;
	int i,j,a[20],sum=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	qsort(a,n,sizeof(a[0]),cmp);
	
	for(i=0;i<n-k;i++)
		sum+=a[i];
	for(i=n-k;i<n;i++)
		sum*=a[i];
	printf("%d\n",sum);
	
	
	return 0;
}
