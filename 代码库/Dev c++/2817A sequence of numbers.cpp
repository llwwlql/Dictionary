#include <stdio.h>

long long PowerMod(long long a,long long b,int c,long long q)
{
	long long ans=q;
	a=a%c;
	while(b>0)
	{
		if(b%2)
			ans=(ans*a)%c;
		b/=2;
		a=(a*a)%c;
	}
	return ans;
}

int main()
{
	long long a,b,c;
	int k;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d %I64d %I64d %d",&a,&b,&c,&k);
		if(b-a==c-b)
			printf("%d\n",(a+(k-1)*(b-a))%200907);
		else
			printf("%I64d\n",PowerMod(c/b,k-1,200907,a));
	}
	
	return 0;
}
