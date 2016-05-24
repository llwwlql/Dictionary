#include <stdio.h>
typedef unsigned long UL;
UL LCM(UL a,UL b)
{
	UL temp,index1,index2;
	index1=a;
	index2=b;
	temp=a%b;
	while(temp)
	{
		a=b;
		b=temp;
		temp=a%b;
	}
	return index1*index2/b;
}
int main()
{
	int n;
	UL a,b;
	int i;
	while(~scanf("%d",&n))
	{
		a=1;
		for(i=0;i<n;i++)
		{
			scanf("%lu",&b);
			a=LCM(a,b);
		}
		printf("%lu\n",a);
	}
	return 0;
}
