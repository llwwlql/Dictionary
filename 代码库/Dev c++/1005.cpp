#include <stdio.h>
int main()
{
	int A,B;
	long long n;
	int i,j;
	while(scanf("%d %d %I64d",&A,&B,&n),A||B||n)
	{
		int a[3];
		a[0]=a[1]=1;
		for(i=2;i<n;i++)
			a[i%3]=(A*a[(i-1)%3]+B*a[(i-2)%3])%7;
		printf("%d\n",a[(n-1)%3]);
	}
	
	return 0;
}
