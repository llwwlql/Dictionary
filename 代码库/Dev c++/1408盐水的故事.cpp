#include <stdio.h>
int main()
{
	double n,d;
	int i;
	while(~scanf("%lf %lf",&n,&d))
	{
		i=0;
		int index=1,time=0;
		while(n>0)
		{
			if(i==index)
			{
				i=0;
				index++;
				time++;
			}
			n-=d;
			time++;
			i++;
		}
		printf("%d\n",time);
	}
	
	return 0;
}
