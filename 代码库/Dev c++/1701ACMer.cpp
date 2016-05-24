#include <stdio.h>
#include <math.h>
int main()
{
	int i;
	double Q,P;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int sum1,sum2;
		scanf("%lf %lf",&P,&Q);
		for(i=0;;i++)
		{
			sum1=(int)i*P/100;
			sum2=(int)i*Q/100;
			if(sum1<sum2)
				break;
		}
		printf("%d\n",i);
	}
	
	return 0;
}
