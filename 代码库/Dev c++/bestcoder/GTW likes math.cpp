#include <stdio.h>
int a,b,c,l,r;
double fun(int index)
{
	return a*index*index+b*index+c;
}

int main()
{

	int T;
	int i,temp;
	scanf("%d",&T);
	while(T--)
	{
		int max=-100000000,min=10000000;
		double index;
		scanf("%d %d %d %d %d",&a,&b,&c,&l,&r);
		if(l>r)
		{
			temp=l;
			l=r;
			r=temp;
		}
		for(i=l;i<=r;i++)
		{
			temp=fun(i);
			if(temp>max)
				max=temp;
			if(temp<min)
				min=temp;
		}
		
		printf("%d %d\n",max,min);
	}
	
	return 0;
}
