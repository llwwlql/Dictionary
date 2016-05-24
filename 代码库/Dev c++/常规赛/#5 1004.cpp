#include <stdio.h>
int main()
{
	int n;
	int a,i,sum;
	while(scanf("%d",&n),n)
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			sum=sum^a;
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
