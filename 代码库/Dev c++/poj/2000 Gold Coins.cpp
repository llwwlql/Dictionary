#include <stdio.h>
int main()
{
	int n;
	int i,j,temp,index;
	int a[10005];
	temp=1;
	index=0;
	a[0]=0;
	for(i=1;i<=10000;i++,index++)
	{
		if(index==temp)
		{
			index=0;
			temp++;
		}
		a[i]=a[i-1]+temp;
	}
	while(scanf("%d",&n),n)
	{
		printf("%d %d\n",n,a[n]);
	}
	
	return 0;
}
