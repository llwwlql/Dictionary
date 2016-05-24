#include <stdio.h>
int main()
{
	int n,u,d;
	while(scanf("%d %d %d",&n,&u,&d),n||u||d)
	{
		int time=0;
		int len=0;
		while(len<n)
		{
			if(len+u>=n)
			{
				time++;
				len+=u;
			}
			else
			{
				len+=u-d;
				time+=2;
			}
		}
		printf("%d\n",time);
	}
	
	return 0;
}
