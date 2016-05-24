#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int T,i;
	int n,v,w;
	int a[105];
	float p;
	int sum_v;
	scanf("%d",&T);
	while(T--)
	{
		sum_v=0;
		p=.0;
		scanf("%d %d %d",&n,&v,&w);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		qsort(a,n,sizeof(int),cmp);
		
		
		for(i=0;i<n;i++)
		{
			if((float)(sum_v*p+a[i]*1.0/100*v)*1.0/(sum_v+v)<=w*1.0/100)
			{
				p=(float)(sum_v*p+a[i]*1.0/100*v)*1.0/(sum_v+v);
				sum_v+=v;
			}
			
			else
			{
				printf("%d %.2lf\n",sum_v,p);
				break;
			}
		}
		
		if(i==n)
			printf("%d %.2lf\n",sum_v,p);
	}
	
	return 0;
}
