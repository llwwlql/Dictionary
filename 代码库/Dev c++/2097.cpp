#include <stdio.h>
int main()
{
	int num,num1,num2,n,temp;
	int i;
	while(scanf("%d",&n),n)
	{
		num=0;
		temp=n;
		while(temp)
		{
			num+=temp%10;
			temp/=10;
		}
		num1=num2=0;
		temp=n;
		while(temp)
		{
			num1+=temp%16;
			temp/=16;
		}
		temp=n;
		while(temp)
		{
			num2+=temp%12;
			temp/=12;
		}
		if(num==num1 && num==num2)
			printf("%d is a Sky Number.\n",n);
		else
			printf("%d is not a Sky Number.\n",n);
	}
	
	return 0;
}
