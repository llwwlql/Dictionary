#include <stdio.h>
int main()
{
	int n;
	int x,y;
	int a,b;
	int index1,index2,i;
	double sum;
	while(scanf("%d",&n),n)
	{
		sum=.0;
		scanf("%d %d",&x,&y);
		index1=x;
		index2=y;
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			sum+=x*b-a*y;
			x=a;
			y=b;
		}
		sum+=x*index2-y*index1;
		printf("%.1f\n",sum*0.5);
	}
	
	return 0;
}
