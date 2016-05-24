#include <stdio.h>
int main()
{
	int n,sum1,sum2,sum3,sum;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;
		sum1=n/2;
		sum2=(n-sum1)*2/3;
		sum3=n-sum1-sum2;
		if(sum1%10)
			sum++;
		if(sum2%10)
			sum++;
		if(sum3%10)
			sum++;
		sum+=sum1/10+sum2/10+sum3/10;
		printf("%d\n",sum);
	}
	
	return 0;
}
