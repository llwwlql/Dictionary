#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int edge[105][105];
	int i,j,k; 
	int n,q,a,b;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			edge[i][j]=1005;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&edge[i][j]);
	}
	
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(edge[i][k]+edge[k][j]<edge[i][j])
					edge[i][j]=edge[i][k]+edge[k][j];
			}
		}
	}
	
	scanf("%d",&q);
	
	while(q--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",edge[a][b]);
	}	
	
	return 0;
}
