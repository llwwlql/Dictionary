#include <stdio.h>
#include <math.h>
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m),n||m)
	{	
		double temp=sqrt(n*n-4*m),x,y;
		if(n*n-4*m<0 || temp!=floor(temp))
			printf("NO\n");
		else
		{
			x=(temp+n)/2;
			y=(n-temp)/2;
			if(x==floor(x) && y==floor(y))
				printf("YES\n");
			else
				printf("NO\n");
		} 
	}
	return 0;
}
