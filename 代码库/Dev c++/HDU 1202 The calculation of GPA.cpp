#include <stdio.h>
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		double sum1,sum2;
		double s,p;
		sum1=sum2=.0;
		while(n--)
		{
			scanf("%lf %lf",&s,&p);
			if(p!=-1)
			{
				sum1+=s;
				if(p>=90)
					sum2+=s*4;
				else if(p>=80)
					sum2+=s*3;
				else if(p>=70)
					sum2+=s*2;
				else if(p>=60)
					sum2+=s*1;
			}
		}
		if(sum1!=0)
			printf("%.2lf\n",sum2*1.0/sum1);
		else
			printf("-1\n");
	}
	
	return 0;
}
