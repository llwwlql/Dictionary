#include <stdio.h>
int main()
{
	int a[15];
	a[0]=1;
	a[1]=1;
	int T;
	int n,i,j;
	
	for(i=2;i<=10;i++)
		a[i]=a[i-1]*i;
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(T==0)
		printf("%d",a[n]);
		else
		printf("%d\n",a[n]);
	}
	
	return 0;
}
