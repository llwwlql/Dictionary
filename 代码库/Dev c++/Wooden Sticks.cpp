#include <stdio.h>
typedef struct {
	int a;
	int b;
}Wooden;

int T,n;
void sort(Wooden *L)
{
	Wooden temp;
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(L[i].a<L[j].a)
			{
				temp=L[i];
				L[i]=L[j];
				L[j]=temp;
			}
		}
	}
}

int main()
{
	Wooden L[5005];
	int i,j,index,max_l,max_m,peace;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d %d",&L[i].a,&L[i].b);
		sort(L);
		peace=1;
		index=0;
		while(peace)
		{
			max_l=10000;
			max_m=10000;
			peace=0;
			for(i=1;i<=n;i++)
			{
				if(L[i].a)
				{
					if(max_l>=L[i].a && max_m>=L[i].b)
					{
						max_l=L[i].a;
						max_m=L[i].b;
						L[i].a=0;
					}
					peace=1;
				}
			}
			index++;
		}
		printf("%d\n",index-1);
	}
	
	return 0;
}
