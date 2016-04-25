#include <stdio.h>
#include <math.h>
int main()
{
	int n,m;
	int i,j;
	int T,peace;
	double a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		a=(n-2)*180/n;
		b=(m-2)*180/m;
		peace=0;
		for(i=0;a*i<=360 && !peace;i++)
		{
			for(j=0;a*i+b*j<=360 && !peace;j++)
			{
				if(fabs(a*i+b*j-360)<0.00001)
					peace=1;
			}
		}
		if(peace)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
