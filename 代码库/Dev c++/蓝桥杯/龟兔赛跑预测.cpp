#include <stdio.h>
int main()
{
	int v1,v2,s,t;
	double time1,time2,l;
	int v;
	scanf("%d %d %d %d %lf",&v1,&v2,&t,&s,&l);
	time2=l/v2;
	time1=.0;
	v=v1-v2;
	while(l>0)
	{
		if(t/v<l/v1)
		{
			time1+=t*1.0/v+s;
			l=l-v1*t*1.0/v;
		}
		else if(t/v==l/v1)
		{
			time1+=t*1.0/v;
			l=0;
		}
		else
		{
			time1+=l*1.0/v1;
			l=0;
		}
	}
	if(time1>time2)
		printf("T\n%g\n",time2);
	else if(time1<time2)
		printf("R\n%g\n",time1);
	else
		printf("D\n%g\n",time1);
	
	return 0;
}
