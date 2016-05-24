#include <stdio.h>
int main()
{
	int a[105],n,m;
	int T,temp,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]<a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		printf("%d\n",(100-a[n-m+1])*(100-a[n-m]));
				
	}
	
	return 0;
}
