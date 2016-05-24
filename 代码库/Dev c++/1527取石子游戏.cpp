//威佐夫博弈 m(k)是前面没有出现过的最小自然数，n(k)=m(k)+k。 
//m(k)=k*(1+sqrt(5))/2   n(k)=m(k)+k
#include <stdio.h>
#include <math.h>
int main()
{
	long long n,m,k;
	while(~scanf("%I64d %I64d",&n,&m))
	{
		if(m<n)
		{
			int temp=n;
			n=m;
			m=temp;
		}
		
		k=m-n;
		
		n=k*(1+sqrt(5.0))/2.0;
		
		if(m==n+k)
			printf("0\n");
		else
			printf("1\n");
		
	}
	
	return 0;
}
