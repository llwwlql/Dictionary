#include <stdio.h>
int main()
{
	int n;
	int T;
	int i,a;
	scanf("%d",&T);
	while(T--)
	{
		int max=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(a>max)
				max=a;
		}
		
		printf("%d\n",max);
		
	}
	
	return 0;
}
