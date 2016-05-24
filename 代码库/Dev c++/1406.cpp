#include <stdio.h>
int fun(int n)
{
	int i,sum=0;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
			sum+=i;
	}
	if(sum==n)
		return 1;
	else
		return 0;
}

int main()
{
	int n,num1,num2,temp;
	int i,j;
	scanf("%d",&n);
	while(n--)
	{
		int index=0;
		scanf("%d %d",&num1,&num2);
		if(num1>num2)
		{
			temp=num1;num1=num2;num2=temp;
		}
		for(i=num1;i<=num2;i++)
		{
			if(fun(i))
				index++;
		}
		printf("%d\n",index);
	}
	
	return 0;
}
