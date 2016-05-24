#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	int i,j;
	int a[70],sum,count,temp;
	a[1]=1;
	temp=2;
	count=0;
	sum=2;
	for(i=2;i<=64;i++)
	{
		a[i]=a[i-1]+sum;
		count++;
		if(count==temp)
		{
			sum*=2;
			temp++;
			count=0;
		}
	}
	while(~scanf("%d",&n))
		printf("%d\n",a[n]);

	return 0;
}
