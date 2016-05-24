#include <stdio.h>
int main()
{
	int money,q;
	double sum,e,f,g;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %lf %lf %lf",&money,&q,&e,&f,&g);
		sum=money*(1+e/100*(q*1.0/365));
		sum=sum*(1+g/100);
		printf("%.1lf\n",sum);
		sum=money*(1+f/100*(q+365)*1.0/365);
		printf("%.1lf\n",sum);
	}
	
	return 0;
}
