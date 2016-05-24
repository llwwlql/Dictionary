#include <stdio.h>
#include <string.h>
int main()
{
	int T,N;
	int a[105][105];
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		memset(a,0,sizeof(a));
		for(i=1;i<=N;i++)
			for(j=1;j<=i;j++)
				scanf("%d",a[i]+j);
		for(i=N;i>1;i--)
		{
			for(j=1;j<=i;j++)
			{
				if(a[i][j]>a[i][j+1])
					a[i-1][j]+=a[i][j];
				else
					a[i-1][j]+=a[i][j+1];
			}
		}
		printf("%d\n",a[1][1]);
	}
	
	return 0;
}
