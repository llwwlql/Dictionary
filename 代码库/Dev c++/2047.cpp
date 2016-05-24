#include <stdio.h>
int main()
{
	int n,i;
	long long a[50];
	a[0]=1;
	a[1]=3;
	for(i=2;i<40;i++)
		a[i]=(a[i-1]+a[i-2])*2;
	while(~scanf("%d",&n))
	{
		printf("%I64d\n",a[n]);
	}
	
	return 0;
}
