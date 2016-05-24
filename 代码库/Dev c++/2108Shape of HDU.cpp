#include <stdio.h>
int main()
{
	int n;
	int i,sum;
	int x[1005],y[1005];
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d %d",x+i,y+i);
		
		x[n]=x[0];
		y[n]=y[0];
		x[n+1]=x[1];
		y[n+1]=y[1];
		
		for(i=0;i<n;i++)
		{
			sum=(x[i+1]-x[i])*(y[i+2]-y[i])-(x[i+2]-x[i])*(y[i+1]-y[i]);//根据向量叉乘得 
			if(sum<0)
				break;
		}
		
		if(i!=n || sum<0)
			printf("concave\n");
		else
			printf("convex\n");
	}
	
	return 0;
}
