#include <stdio.h>
int main()
{
	int f[25];
	int i,n,T;
	f[1]=0;
	f[2]=1;
	for(i=3;i<=20;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		long long sum=1;
		for(i=2;i<=n;i++)
			sum*=i;
		printf("%.2lf%%\n",(float)f[n]*100/sum);
	}
	
	return 0;
}
