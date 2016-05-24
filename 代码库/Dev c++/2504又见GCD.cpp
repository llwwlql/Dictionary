#include <stdio.h>

int gcd(int a,int b)
{
	int temp;
	if(a<b)
	{
		temp=a;a=b;b=temp;
	}
	while(a%b)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	return b;
}

int main()
{
	int T;
	int a,b,d,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&a,&b);
		d=a/b;
		for(i=2;1;i++)
		{
			if(gcd(d,i)==1)
			{
				printf("%d\n",i*b);
				break;
			}
		}
	}
	
	return 0;
}
