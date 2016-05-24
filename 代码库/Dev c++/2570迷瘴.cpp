#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int n,W,p[105],V,T;
	int i,j;
	int index;
	double sum;
	scanf("%d",&T);
	while(T--)
	{
		index=0;
		sum=0.0;
		scanf("%d %d %d",&n,&V,&W);
		for(i=0;i<n;i++)
			scanf("%d",p+i);
		qsort(p,n,sizeof(p[0]),cmp);
		
		for(i=0;i<n;i++)
		{
			if(sum*index+p[i]<=W*(index+1))
			{
				index++;
				sum=(sum*(index-1)+p[i])/index;
			}
			else
				break;
		}
		printf("%d %.2lf\n",index*V,sum/100.0);
		
	}
	
	return 0;
}
