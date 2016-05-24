#include <stdio.h>
#include <string.h>
int fun(int a)
{
	int i,sum;
	sum=0;
	for(i=1;i<a;i++)
		if(a%i==0 && i!=a/i)
			sum+=i;
		
	if(a==sum)
		return 1;
	else
		return 0;
	
}

int main()
{
	int n,num1,num2;
	int i,j;
	int a[10005];
	memset(a,0,sizeof(a));
	for(i=2;i<=10000;i++)
	{
		if(fun(i))
			a[i]=a[i-1]+1;
		else
			a[i]=a[i-1];
	}
	scanf("%d",&n);
	while(n--)
	{
		int temp,index=0;
		scanf("%d %d",&num1,&num2);
		if(num2<num1)
		{
			temp=num1;num1=num2;num2=temp;
		}
		index=a[num2]-a[num1];
		if(fun(index))
			index++;
		printf("%d\n",index);
	}
	
	return 0;
}
