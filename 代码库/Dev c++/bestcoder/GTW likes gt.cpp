#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[50005],b[50005],c[50005],d[50005];

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int T;
	int i,j;
	int n,m;
	int num;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		num=n;
		for(i=1;i<=n;i++)
			scanf("%d %d",a+i,b+i);
		for(i=1;i<=m;i++)
			scanf("%d",c+i);
		c[m+1]=-1;
		qsort(c,m,sizeof(c[0]),cmp);
		memset(d,0,sizeof(d));
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=c[i];j++)
				b[j]++;
			if(c[i]!=c[i+1])
			{
				int index1=-1,index2=-1;
				for(j=n;j>=1;j--)
				{
					if(a[j]==0 && b[j]<index2 || a[j]==1 && b[j]<index1)
					{
						a[j]=3;
						num--;
					}
					if(a[j]==0 && b[j]>index1)
						index1=b[j];
					if(a[j]==1 && b[j]>index2)
						index2=b[j];
				}
			}
		}
		printf("%d\n",num);
	}
	
	return 0;
}
