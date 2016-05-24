#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct{
	int h,m;
	double du,du1,du2;	
}A;
A a[10];
void sort()
{
	int i,j;
	A temp;
	for(i=1;i<5;i++)
	{
		for(j=i+1;j<=5;j++)
		{
			if(a[i].du>a[j].du)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else if(a[i].du==a[j].du)
			{
				if(a[i].h>a[j].h)
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
	}
	
}

int main()
{
	int T;
	int i,j,h,m;
	scanf("%d",&T);
	while(T--)
	{
		for(i=1;i<=5;i++)
		{
			scanf("%d:%d",&a[i].h,&a[i].m);
			a[i].du1=(a[i].h)%12*30+a[i].m*0.5;
			a[i].du2=a[i].m*6;
			if(a[i].du1>a[i].du2)
				a[i].du=a[i].du1-a[i].du2;
			else
				a[i].du=a[i].du2-a[i].du1;
			if(a[i].du>180)
				a[i].du=fabs(a[i].du-360);	
		}
		
		sort();
		printf("%02d:%02d\n",a[3].h,a[3].m);
		
	}
	return 0;
}
