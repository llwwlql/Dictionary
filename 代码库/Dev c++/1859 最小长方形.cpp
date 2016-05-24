#include <stdio.h>
int cmp_max(int a,int b)
{
	return a>b? a:b;
}
int cmp_min(int a,int b)
{
	return a>b? b:a;
}

int main()
{
	int x,y;
	int max_y,min_y,max_x,min_x;
	while(scanf("%d %d",&x,&y),x||y)
	{
		max_y=max_x=-1000000;min_x=min_y=10000000;
		while(x||y)
		{
			max_y=cmp_max(max_y,y);
			min_y=cmp_min(min_y,y);
			max_x=cmp_max(max_x,x);
			min_x=cmp_min(min_x,x);
			
			scanf("%d %d",&x,&y);
		}
		
		printf("%d %d %d %d\n",min_x,min_y,max_x,max_y);
	}
	
	return 0;
}
