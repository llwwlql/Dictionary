#include <stdio.h>
int main()
{
	int T;
	int n,i,j;
	double a[105],b[105];
	scanf("%d",&T);
	while(T--)
	{
		double sum1=.0,sum2=.0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%lf %lf",a+i,b+i); 
		
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				double temp=.0;
				if(a[i]>a[j])
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
		
		for(i=1;i<=n;i++)
		{
			if(i%2==1)
				sum1+=b[i];
			else
				sum2+=b[i];
		}
		if(sum1>sum2)
			printf("red\n");
		else if(sum1<sum2)
			printf("blue\n");
		else
			printf("fair\n");
	}
	
	return 0;
}
