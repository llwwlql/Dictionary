#include <stdio.h>
int a[1000005];
int main()
{
	int i,j;
	int n;
	a[1]=1;
	a[2]=a[3]=2;
	a[4]=a[5]=4;
	for(i=6;i<=1000000;i++)
	{
		if(i%2)
			a[i]=a[i-1];
		else
			a[i]=(a[i-2]+a[i-4])%1000000000;
	}
	while(~scanf("%d",&n))
		printf("%d\n",a[n]);
	
	
	return 0;
}
