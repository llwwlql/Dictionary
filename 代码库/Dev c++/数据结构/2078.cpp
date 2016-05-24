#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int T;
	int n,m,i; 
	int a[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		qsort(a,n,sizeof(a[0]),cmp);
		printf("%d\n",(100-a[0])*(100-a[0]));
	}
	
	return 0;
}
