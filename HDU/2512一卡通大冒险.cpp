#include <stdio.h>
int a[2005][2005];
int main()
{
	int T,n;
	int i,j;
	a[0][0]=1;
	for(i=1;i<=2000;i++)
	{
		a[i][0]=1;
		for(j=1;j<=i;j++)
			a[i][j]=(a[i-1][j-1]+a[i-1][j])%1000;
	}
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		long long sum=1;
		double len=n/2.0;
		for(i=1;i<len;i++)
		{
			sum=(sum+a[n][i])%1000;
			printf("%I64d %d\n",sum,a[n][i]);
		}
			
		if(n!=1)
			sum=(sum+1)%1000;
		printf("%I64d\n",sum);
	}
	
	return 0;
}
