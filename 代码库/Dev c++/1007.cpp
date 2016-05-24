#include <stdio.h>
#include <math.h>
typedef struct node{
	double x,y;
}Node;

int main()
{
	int n,T,i,j;
	double sum_x,sum_y;
	Node G[105];
	scanf("%d",&T);
	while(T--)
	{
		int peace=0;
		sum_x=sum_y=.0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lf %lf",&G[i].x,&G[i].y);
			sum_x+=G[i].x;
			sum_y+=G[i].y;
		}
		sum_x/=1.0*n;
		sum_y/=1.0*n;
		
		double min=sqrt((G[0].x-sum_x)*(G[0].x-sum_x)+(G[0].y-sum_y)*(G[0].y-sum_y));
		
		
		
		for(i=1;i<n && !peace;i++)
		{
			if(sqrt((G[i].x-sum_x)*(G[i].x-sum_x)+(G[i].y-sum_y)*(G[i].y-sum_y))!=min)
				peace=1;
		}
		
		if(peace)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
