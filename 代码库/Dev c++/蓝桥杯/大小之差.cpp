#include <stdio.h>

int fun(int n)
{
	int i,j,k,index;
	int sum1=0,sum2=0;
	int temp[10];
	i=0;
	while(n)
	{
		temp[i++]=n%10;
		n/10;
	}
	
	for(j=0;j<i-1;j++)
	{
		for(k=j+1;k<i;j++)
		{
			if(temp[j]<temp[k])
			{
				index=temp[j];
				temp[j]=temp[k];
				temp[k]=index;
			}
		}
	}
	
	for(j=0,k=i-1;j<i;j++,k--)
	{
		sum1=sum1*10+temp[j];
		sum2=sum2*10+temp[k];
	}
	sum1=sum1-sum2;
	
	while(sum1)
	{
		index=sum1%10;
		sum1/=10;
		for(j=0;j<i;j++)
			if(temp[j]==index)
				temp[j]=0;
	}
	for(j=0;j<i;j++)
		if(temp[j]!=0)
			return 0;
	return 1;
}


int main()
{
	int i;
	for(i=50000;i<1000000;i++)
	{
		if(fun(i))
		{
			printf("%d\n",i);
			break;
		}
	}
	
	return 0;
}
