#include <stdio.h>
int main()
{
	double h,l,v;
	double a,b,c,g;
	g=9.8;
	while(scanf("%lf %lf %lf",&h,&l,&v),h||l||v)
	{
		c=a=-(l*l*g)/(2.0*v*v);
		b=l;
		
		printf("%.2lf\n",(4.0*a*c-b*b)/(4.0*a)+h);
		
	}
	
	return 0;
}
