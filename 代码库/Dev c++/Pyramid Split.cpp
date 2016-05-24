#include <stdio.h>
#include <math.h>
int main()
{
	int T,n;
	int a[10005],b[10005];
	double average,s,x,temp;
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		average=.0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		s=a[1]*b[1]*b[1]*1.0/3;
		s/=2.0;
		x=pow(3*s*a[1]*a[1]/b[1]/b[1],1.0/3);
		average+=a[1]*1.0-x;
		for(i=2;i<=n;i++)
		{
			s=a[i]*b[i]*b[i]*1.0/3;
			s/=2.0;
			x=pow(3*s*a[i]*a[i]/b[i]/b[i],1.0/3);
			average+=a[i]*1.0-x;
			average/=2.0;
		}
		printf("%.0f\n",average);
	}
	
	return 0;
}
