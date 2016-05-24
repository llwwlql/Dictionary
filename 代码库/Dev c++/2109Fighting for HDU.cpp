#include <stdio.h>
#include <stdlib.h>
int cmp ( const void *a , const void *b )  
{  
	return *(int *)a - *(int *)b;  
}  


int main()
{
	int n;
	int a[105],b[105];
	int i,j;
	while(scanf("%d",&n),n)
	{
		int sum1=0,sum2=0;
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n;i++)
			scanf("%d",b+i);
		qsort(a,n,sizeof(a[0]),cmp);
		qsort(b,n,sizeof(b[0]),cmp);
		
		for(i=0;i<n;i++)
		{
			if(a[i]>b[i])
				sum1+=2;
			else if(a[i]<b[i])
				sum2+=2;
			else
			{
				sum1+=1;
				sum2+=1;
			}
		}
		printf("%d vs %d\n",sum1,sum2);
	}
	
	return 0;
}
