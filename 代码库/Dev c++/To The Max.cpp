#include <stdio.h>
#include <stdlib.h>
int a[105][105];
int MAX_SUM(int n,int *m)
{
	int b=0,i;
	int sum=-100000;
	for(i=1;i<=n;i++)
	{
		if(b>0)
			b+=m[i];
		else
			b=m[i];
		if(b>sum)
			sum=b;
	}
	return sum;
}
int MAX_SUM2(int n)
{
	int i,j,k,sum=-10000;
	int *b=(int *)malloc((n+1)*sizeof(int));
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=n;k++)
			b[k]=0;
		for(j=i;j<=n;j++)
		{
			for(k=1;k<=n;k++)
				b[k]+=a[j][k];
			int max=MAX_SUM(n,b);
				if(max>sum)
					sum=max;
		}
	}
	free(b);
	return sum;
}


int main()
{
	int n;
	int i,j;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%d",a[i]+j);
		}
		
		printf("%d\n",MAX_SUM2(n));
	}
	
	return 0;
}
