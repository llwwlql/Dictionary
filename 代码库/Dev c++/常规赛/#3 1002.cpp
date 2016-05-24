#include <stdio.h>
#include <string.h>
typedef struct {
	int a,b;
	int index;
	double num;
}NUM;
NUM A[1005];

void sort(int n)
{
	int i,j;
	int index;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(A[i].b<A[j].b)
			{
				index=A[i].a;
				A[i].a=A[j].a;
				A[j].b=index;
				
				index=A[i].b;
				A[i].b=A[j].b;
				A[j].b=index;
			}
			
			else if(A[i].b==A[j].b && A[i].num<A[j].num)
			{
				index=A[i].a;
				A[i].a=A[j].a;
				A[j].b=index;
				
				index=A[i].b;
				A[i].b=A[j].b;
				A[j].b=index;				
			}
		}
	}
	
}

int main()
{
	int n,v;
	int T,i,j;
	int a[1005],b[1005];
	int index[1005],peace,Peace;
	scanf("%d",&T);
	while(T--)
	{
		Peace=1;
		scanf("%d %d",&v,&n);
		for(i=0;i<=n;i++)
			A[i].index=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&A[i].a,&A[i].b);
			A[i].num=A[i].b*1.0/A[i].a;
			if(A[i].b>v)
			{
				printf("No\n");
				Peace=0;
			}
			printf("%lf\n",A[i].num);
		}
		if(Peace)
		{
			sort(n);
			
			for(i=0;i<n;i++)
			{
				peace=1;
				for(j=0;j<n && peace;j++)
				{
					if(!A[j].index && A[j].b>=v)
					{
						peace=0;
						A[j].index=1;
						v-=A[j].a;
					}
				}
			}
			peace=1;
			
			for(i=0;i<n && peace;i++)
			{
				if(!A[i].index)
					peace=0;
			}
			if(peace)
				printf("Yes\n");
			else
				printf("No\n");
		}
		
	}
	
	return 0;
}
