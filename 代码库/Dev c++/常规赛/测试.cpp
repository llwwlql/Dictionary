#include <stdio.h>
int main()
{
	int i,T,a[25],n;
	scanf("%d",&T);
	a[1]=3;
	a[2]=7;
	for(i=3;i<=20;i++)
		a[i]=a[i-1]*2+a[i-2];
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
