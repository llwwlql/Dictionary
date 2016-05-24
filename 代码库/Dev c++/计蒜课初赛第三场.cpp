#include <stdio.h>
int main()
{
	int T,n;
	double area;
	int i,j;
	int a[1005],b[1005],r[1005];
	scanf("%d",&T);
	while(T--)
	{
		area=.0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%f %f %f",r+i,a+i,b+i);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(r[i]<=r[j])
				{
					if(a[i]>a[j] && a[i]<b[j])
						a[i]=b[j];
					if(b[i]>a[j] && b[i]<b[j])
						b[i]=a[j];
					if(a[i]>a[j] && b[i]<b[j])
						r[i]=0;
				}
			}
		for(i=0;i<n;i++)
		    area=area+(b[i]-a[i])*3.14159265*r[i]*r[i]/360;
        printf("%.3lf\n",area);
		
	}
	
	return 0;
}
