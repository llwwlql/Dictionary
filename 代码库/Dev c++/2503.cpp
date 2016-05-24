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
	int T,i,j;
	int a,b,c,d,e,f,temp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		f=b*d;	
		e=b*c+a*d;	//分数的加法 
		if(e==f)
		{
			printf("1 1\n");
			continue;
		}
		temp=gcd(e,f);//计算最大公约数 
		printf("%d %d\n",e/temp,f/temp);	//进行最简化 
	}
	
	return 0;
}
