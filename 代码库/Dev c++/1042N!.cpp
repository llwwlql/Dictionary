#include <stdio.h>
int main()
{
	long long sum[1005];
	int n,i;
	sum[0]=sum[1]=1;
	for(i=2;i<=50;i++)
		sum[i]=sum[i-1]*i;
	while(~scanf("%d",&n))
	{
		printf("%I64d\n",sum[n]);
	}
	
	return 0;
}
