#include <stdio.h>
int PowerMod(int a,int b,int c)
{
	int ans;
	ans=1;
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
	int n,b,T;
	int ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=PowerMod(n,n,10);
		printf("%d\n",ans);
	}
	
	return 0;
}
