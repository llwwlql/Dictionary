#include <stdio.h>
int a[1005][1005];

int main()
{
	int n,k;
	int i,j,T;
	int b; 
	scanf("%d",&T);
	a[0][0]=1;
	for(i=1;i<=1000;i++)
	{
		a[i][0]=1;
		for(j=1;j<=i;j++)
			a[i][j]=(a[i-1][j-1]+a[i-1][j])%10000003;
	}
	
	while(T--)
	{
		scanf("%d %d",&n,&b);
		if(T!=0)
			printf("%d\n",a[n][b]);
		else
			printf("%d",a[n][b]);
	}
	
	return 0;
}
