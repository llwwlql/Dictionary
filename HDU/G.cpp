#include <stdio.h>
#include <string.h>
#define MOD 1000000007
int s[105][105];
int main()
{
	int n,m;
	int i,j;
	long long sum=1;
	memset(s,0,sizeof(s));
	s[1][1]=1;
	for(i=2;i<=100;i++)
	{
		for(j=1;j<=i;j++)
			s[i][j]=(s[i-1][j-1]+(s[i-1][j]*j)%MOD)%MOD;
	}
	while(~scanf("%d %d",&n,&m))
	{
		sum=1; 
		for(i=1;i<=m;i++)
			sum=(sum*i)%MOD;
		sum=(s[n][m]*sum)%MOD;
		printf("%I64d\n",sum);
	}	
	return 0;
}
