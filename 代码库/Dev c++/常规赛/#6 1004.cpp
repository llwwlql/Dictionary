#include <stdio.h>
int map[105][105];
int main()
{
	int n,m;
	int i,j,k,a,b,t;
	while(scanf("%d %d",&n,&m),n||m)
	{
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			map[i][j]=1000005;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d %d",&a,&b,&t);
			map[a][b]=t;
			map[b][a]=t;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(map[i][j]>map[i][k]+map[k][j])
						map[i][j]=map[i][k]+map[k][j];
				}
			}
		}
		printf("%d\n",map[1][n]);
	
	}
	
	return 0;
}
