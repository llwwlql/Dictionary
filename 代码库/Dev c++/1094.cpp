#include <stdio.h>
int main()
{
	int n,a;
	int T,sum,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		sum=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
		if(i!=T)
			putchar('\n');
	}
	
	return 0;
}
