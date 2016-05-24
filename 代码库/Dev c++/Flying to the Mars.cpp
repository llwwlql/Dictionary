#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *a,const void *b)
{
	return *(long long *)a-*(long long *)b;
}

int main()
{
	int n;
	int i,index;
	long long a[3005];
	int max;
	while(~scanf("%d",&n))
	{
		max=1;
		index=1;
		
		for(i=0;i<n;i++)
			scanf("%I64d",a+i);
		
		qsort(a,n,sizeof(long long),comp);
		
		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
				index++;
			else
				index=1;
			if(index>max)
				max=index;
		}
		
		printf("%d\n",max);
	}
	return 0;
}
