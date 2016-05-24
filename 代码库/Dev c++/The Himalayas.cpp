#include <stdio.h>
#include <string.h>
int main()
{
	int T,n,i,a;
	int b[8900];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			b[a]++;
		}
		int max=0;
		for(i=0;i<=8900;i++)
			if(b[i]>max)
				max=b[i];
		printf("%d\n",max);
	}
	
	return 0;
}
