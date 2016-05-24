#include <stdio.h>
int main()
{
	int n,u,d;
	int i,j;
	int index,time;
	while(scanf("%d %d %d",&n,&u,&d),n)
	{
		index=0;
		time=0;
		while(index!=n)
		{
			if(index+u>=n)
			{
				index=n;
				time++;
			}
			else
			{
				index+=u-d;
				time+=2;
			}
		}
		printf("%d\n",time);
	}
	
	return 0;
}
