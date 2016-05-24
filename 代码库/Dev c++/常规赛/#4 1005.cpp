#include <stdio.h>
int main()
{
	int i;
	long long a[1005];
	int n;
	a[1]=1;
	for(i=2;i<=1005;i++)
		a[i]=a[i-1]+(i-1);
	while(~scanf("%d",&n))
		printf("%I64d\n",a[n]);
	
	return 0;
}
