#include <stdio.h>
int a[1005];
int main()
{
	int T,n;
	int i,j;
	a[1]=1;
	a[2]=2;
	for(i=3;i<=20;i++)
		a[i]=a[i-1]+a[i-2];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	
	return 0;
}
