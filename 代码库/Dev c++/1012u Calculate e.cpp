#include <stdio.h>
int main()
{
	int i,n,sum[12];
	double e=1.;
	printf("n e\n- -----------\n0 1\n");
	sum[0]=1;
	for(n=1;n<=9;n++)
	{
		sum[n]=sum[n-1]*n;
		e=e+1.0/sum[n];
		printf("%d %.10g\n",n,e);
	}
	
	return 0;
}
