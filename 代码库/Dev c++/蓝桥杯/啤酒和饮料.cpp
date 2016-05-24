#include <stdio.h>
#include <math.h>
int main()
{
	int i,j;
	for(i=1;i<=82.3/1.9;i++)
	{
		for(j=1;j<i;j++)
		{
			if(fabs(82.3*1.0-i*1.9-j*2.3)<=0.00001)
				printf("%d\n",j);
		}
	}
	
	return 0;
}
