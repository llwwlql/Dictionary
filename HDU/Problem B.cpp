#include <string.h>
#include <stdio.h> 
int main()
{
	unsigned long long a[205];
	int i,j;
	int n;
	a[0]=1;
	a[1]=1;
	for(i=2;i<=200;i++)
		a[i]=a[i-1]+a[i-2];
	while(~scanf("%d",&n))
	{
		printf("%I64d\n",a[n]);
	}
	
	return 0;
}
