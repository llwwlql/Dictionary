#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,n,N;
	while(scanf("%d",&N),N)
	{
		int a[105];
		memset(a,0,sizeof(a));
		for(i=0;i<N;i++)
		{
			scanf("%d",&n);
			a[n]++;
		}
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	
	return 0;
}
