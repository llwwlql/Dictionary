#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(long long *)a-*(long long *)b;
}
int main()
{
	int n,T,i,j;
	long long a[1005];
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		    scanf("%I64d",a+i);
		qsort(a,n,sizeof(long long),cmp);
		printf("%d",a[0]);
		for (i=1;i<n;i++)
		    printf(" %d",a[i]);
		putchar('\n');
	}
	return 0;
}
