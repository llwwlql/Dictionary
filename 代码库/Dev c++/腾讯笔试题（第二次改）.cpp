#include <stdio.h>
#include <math.h>
int main()
{
	int a[10];
	int i;
	int index=0,temp;
		for(a[1]=0;a[1]<=5;a[1]++)
		{
			a[2]=13-a[1];
			for(a[8]=0;a[8]<=5;a[8]++)
			{
					a[5]=5-a[8];
				for(a[4]=1;a[4]<=100;a[4]++)
				{
					
					if((a[2]-4)%a[4]==0)
					{
						a[7]=(a[2]-4)/a[4];
						a[6]=4+a[8]-a[7];
						a[3]=(4-a[1])*a[6];
						if(a[3]-a[4]*a[5]==4)
						{
							for(i=1;i<=8;i++)
								printf("%d ",a[i]);
							putchar('\n');
							index++;
						}
					}
				}
			}
		}
	printf("%d\n",index);
	return 0;
}
