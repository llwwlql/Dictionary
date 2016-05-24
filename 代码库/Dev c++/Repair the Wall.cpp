#include <stdio.h>
int main()
{
	int n,m;
	int i,j,temp,sum;
	int a[605];
	while(~scanf("%d %d",&m,&n))
	{
		sum=0;
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]<a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(sum+a[i]>=m)
			{
				printf("%d\n",i);
				break;
			}
			else
				sum+=a[i];
		}
		if(i>n)
			printf("impossible\n");
		
	}
	
	return 0;
}
