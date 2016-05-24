#include <stdio.h>
#include <math.h>
int main()
{
	int a[1005];
	int i;
	a[0]=2;
	a[1]=3;
	for(i=2;i<=10;i++)
		a[i]=a[i-1]+a[i-2];
	printf("%lf\n",pow(2,10)+1);
	return 0;
}
