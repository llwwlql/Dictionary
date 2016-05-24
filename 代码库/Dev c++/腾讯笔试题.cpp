#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	float a[10];
	int index=0;
	for(a[1]=.0;a[1]<=4;a[1]++)
	{
		a[2]=13-a[1];
			for(a[4]=.0;a[4]<=100;a[4]++)
			{
				for(a[8]=.0;a[8]<=5;a[8]++)
				{
					a[5]=5-a[8];
					a[3]=4-a[4]*a[5];
					a[6]=a[3]/(4-a[1]);
					a[7]=4-a[6]+a[8];
					if(a[2]-a[4]*a[7]==4)
						for(int i=1;i<=8;i++)
							printf("%d ",a[i]);
				}
			}
	}
	printf("%d\n",index);
	return 0;
}
