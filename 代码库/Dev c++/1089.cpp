#include <stdio.h>
int main()
{
	int n;
	int b,i;
	int sum;
	while(scanf("%d",&n),n)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&b);
			sum+=b;
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
