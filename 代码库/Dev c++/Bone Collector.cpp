#include <stdio.h>
#include <string.h>
int m[1005][1005];
int main()
{
	int T;
	int n,V,i,j;
	int v[1005],w[1005];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&V);
		memset(m,0,sizeof(m));
		for(i=1;i<=n;i++)
			scanf("%d",v+i);
		for(i=1;i<=n;i++)
			scanf("%d",w+i);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=V;j++)
			{
				if(j-w[i]>=0)
				{
					if(m[i-1][j-w[i]]+v[i]>m[i-1][j])
						m[i][j]=m[i-1][j-w[i]]+v[i];
					else
						m[i][j]=m[i-1][j];
				}
				else
					m[i][j]=m[i-1][j];
			}
		}
		printf("%d\n",m[n][V]);
	}
	
	return 0;
}
