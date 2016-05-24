#include <stdio.h>
#include <math.h>
int main()
{
	int T,n,i,j;
	int index,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=pow(2,n-2)*(n-1)+pow(2,n-1);
		printf("%d\n",sum);
	}
	
	return 0;
}
