#include <stdio.h>
int main()
{
	int T;
	int n,i,j;
	double max,a;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		max=.0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&a);
			if(max<a)
				max=a;
		}
		printf("%.2lf\n",max);
	}
	return 0;
}
