#include <stdio.h>
__int64 LCM(int a,int b)
{
	int temp;
	int index1=a,index2=b;
	temp=a%b;
	while(temp)
	{
		a=b;
		b=temp;
		temp=a%b;
	}
	return (index1*index2/b);
}

int main()
{
	__int64 n;
	__int64 a,b;
	__int64 i;
	while(~scanf("%I64d",&n))
	{
		scanf("%I64d %I64d",&a,&b);
		a=LCM(a,b);
		for(i=2;i<n;i++)
		{
			scanf("%I64d",&b);
			a=LCM(a,b);
		}
		printf("%I64d\n",a);
	}
	return 0;
}
