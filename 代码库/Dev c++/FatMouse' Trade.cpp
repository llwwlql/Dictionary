#include <stdio.h>
int main()
{
	int n,m;
	int a[1005],b[1005],i,j,temp;
	double sum;
	while(scanf("%d %d",&m,&n),m!=-1 && n!=-1)
	{
		sum=.0;
		for(i=1;i<=n;i++)
			scanf("%d %d",a+i,b+i);
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]*1.0/b[i]<a[j]*1.0/b[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
					
					temp=b[i];
					b[i]=b[j];
					b[j]=temp;
				}
			}
		}
		for(i=1;i<=n && m;i++)
		{
			if(m>=b[i])
			{
				sum+=a[i];
				m-=b[i];
			}
			else
			{
				sum+=(a[i]*1.0/b[i])*m;
				m=0;
			}
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}
