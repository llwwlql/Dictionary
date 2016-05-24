#include <stdio.h>
int main()
{
	int n;
	int a[4];
	while(scanf("%d",&n),n)
	{
		a[0]=1;
		a[1]=2;
		a[2]=3;
		a[3]=4;
		for(int i=4;i<n;i++)
		{
			a[i%4]=a[(i-1)%4]+a[(i+1)%4];
		}
		printf("%d\n",a[(n-1)%4]);	
	}
	return 0;
}
