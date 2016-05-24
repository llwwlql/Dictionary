#include <stdio.h>
#include <math.h>
void swap(float &a,float &b)
{
	float temp;
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
}

float max(float a,float b)
{
	return a>b? a:b;
}

float min(float a,float b)
{
	return a>b? b:a;
}

int main()
{
	float x[5],y[5];
	while(~scanf("%f %f %f %f %f %f %f %f",x+1,y+1,x+2,y+2,x+3,y+3,x+4,y+4))
	{
		swap(x[1],x[2]);
		swap(y[1],y[2]);
		swap(x[3],x[4]);
		swap(y[3],y[4]);
		
		x[1]=max(x[1],x[3]);
		y[1]=max(y[1],y[3]);
		x[2]=min(x[2],x[4]);
		y[2]=min(y[2],y[4]);
		
		if(x[1]>x[2])
		{
			printf("0.00\n");
		}
		else
		{
			printf("%.2f\n",(x[2]-x[1])*(y[2]-y[1]));
		}
		
	}
	
	return 0;
}
