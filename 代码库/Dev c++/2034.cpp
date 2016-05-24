#include <stdio.h>
int main()
{
	int n,m;
	int a[100],temp;
	int i,j,k;
	while(scanf("%d %d",&n,&m),n||m)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n-1;i++)
		{
			for(j=i;j<n;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&temp);
			for(j=0;j<n;j++)
			{
				if(temp==a[j])
				{
					for(k=j;k<n-1;k++)
						a[k]=a[k+1];
					n--;
				}
			}
		}
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf(n? "\n":"NULL\n");
	}
	return 0;
}
