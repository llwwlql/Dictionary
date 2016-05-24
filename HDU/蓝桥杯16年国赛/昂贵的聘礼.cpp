#include <stdio.h>

int map[105][105];

int main()
{
	int n,m;
	int p,l,x,t,v;
	int i,j,k;
	int a[105];
	while(~scanf("%d %d",&m,&n))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				map[i][j]=1000005;
		}
		
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %d",&p,&l,&x);
			a[i]=l;
			map[i][i]=p;
			for(j=1;j<=x;j++)
			{
				scanf("%d %d",&t,&v);
				map[i][t]=v;
			}		
		}
		
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(map[i][j]>map[i][k]+map[k][j] && a[i]>=a[k] && a[k]>=a[j])
						map[i][j]=map[i][k]+map[k][j];
				}
			}
		}
		printf("%d\n",map[1][1]);
	}
	
	return 0;
}
