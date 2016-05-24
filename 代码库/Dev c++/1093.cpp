#include <stdio.h>
int main()
{
	int T,n;
	int a,sum,i;
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}
	return 0;
}
