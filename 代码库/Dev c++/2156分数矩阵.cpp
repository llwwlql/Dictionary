#include <stdio.h>
int main()
{
	int i,j;
	int n;
	double a[50005];
	
	a[1]=a[0]=.0;
	for(i=2;i<=50000;i++)
		a[i]=a[i-1]+1.0/i;
	
	while(scanf("%d",&n),n)
	{
		double sum=.0;
		for(i=1;i<n;i++)
			sum+=a[n-i+1];
		
		sum*=2.0;
		sum+=n;
		printf("%.2lf\n",sum);
	}
	
	return 0;
}
