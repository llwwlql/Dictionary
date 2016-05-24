#include <stdio.h>
int main()
{
	int i,j,n;
	int a[20];
	a[1]=1;
	for(i=2;i<=10;i++)
	{
		a[i]=a[i-1]*i;
		printf("%d ",a[i]);
	}
	

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(n<=a[i])
			break;
	}
	
	return 0;
}
