#include <stdio.h>
int PowerMod(int a,int b,int c)
{
	int ans=1;
	a%=c;
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
	int a,b;
	while(~scanf("%d %d",&a,&b))
	{
		printf("%d\n",PowerMod(a,b,10));
	}
	
	return 0;
}
