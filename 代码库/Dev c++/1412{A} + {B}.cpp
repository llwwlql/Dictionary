#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int n,m,i,j;
	int a[10005],b[10005];
	while(~scanf("%d %d",&n,&m))
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<m;i++)
			scanf("%d",b+i);
		qsort(a,n,sizeof(int),cmp);
		qsort(b,n,sizeof(int),cmp);
		int peace=1;
		for(i=0,j=0;i!=n && j!=m;)
		{
			if(peace)
				peace=0;
			else
				putchar(' ');			
			
			if(a[i]==b[j])
			{
				printf("%d",a[i]);
				i++;j++;
			}
			else if(a[i]<b[j])
			{
				printf("%d",a[i]);
				i++;
			}
			else
			{
				printf("%d",b[j]);
				j++;
			}
		}
		while(i!=n)
			printf(" %d",a[i++]);
		while(j!=m)
			printf(" %d",b[j++]);
		
		putchar('\n');
	}
	
	return 0;
}
