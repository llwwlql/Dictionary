#include <stdio.h>
#include <stdlib.h>
typedef struct In{
	int v,w;
	double ave;
}V;
int cmp(const void *a,const void *b)
{
	return (*(V *)a).ave > (*(V *)b).ave ? -1 : 1; 
}

int main()
{
	int n,w;
	int i,j,flag;
	V a[10005];
	double sum=.0;
	scanf("%d %d",&n,&w);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].v,&a[i].w);
		a[i].ave=a[i].w*1.0/a[i].v;
	}
	qsort(&a[1],n,sizeof(a[1]),cmp);
	
	
	for(i=1;i<=n && w>0;i++)
	{
		if(w>a[i].v)
		{
			sum+=a[i].w;
			w-=a[i].v;
		}
		else
		{
			sum+=a[i].w*1.0*w/a[i].v;
			w=0;
		}
	}
	
	printf("%.1lf\n",sum);
	
	return 0;
}
