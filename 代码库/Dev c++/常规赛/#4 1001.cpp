#include <stdio.h>
#include <string.h>
int map[1005][1005];
int n,m;
void dfs(int i)
{
	int j;
	for(j=1;j<=n;j++)
	{
		if(map[i][j])
		{
			map[i][j]=0;
			dfs(j);
		}
	}
}

int main()
{
	int i,j;
	int a,b,index;
	while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		memset(map,0,sizeof(map));
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a][b]=1;
			map[b][a]=1;
		}
		for(i=1;i<=n;i++)
			map[i][i]=1;
		index=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(map[i][j])
				{
					map[i][j]=0;
					dfs(j);
					index++;
				}
			}
		}
		printf("%d\n",index-1);
	}
	
	return 0;
}
