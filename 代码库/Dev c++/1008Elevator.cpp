#include <stdio.h>
int main()
{
	int T;
	int sum;
	int i,a[2];
	
	while(scanf("%d",&T),T)
	{
		a[0]=0;
		sum=5*T;
		for(i=1;i<=T;i++)
		{
			scanf("%d",&a[1]);
			if(a[1]>a[0])
				sum+=(a[1]-a[0])*6;
			else if(a[0]>a[1])
				sum+=(a[0]-a[1])*4;
			a[0]=a[1];
		}
		printf("%d\n",sum);
	}
	return 0;
}
