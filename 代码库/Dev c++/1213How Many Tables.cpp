#include <stdio.h>
#include <string.h>
int a,b,n,map[1005][1005];
int ans[1005];
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
	int T,m,peace=1;
	scanf("%d",&T);
	while(T--)
	{
		int index=0;
		scanf("%d %d",&n,&m);
		memset(map,0,sizeof(map));
		memset(ans,0,sizeof(ans));
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a][b]=1;
			map[b][a]=1;
			ans[a]=1;
			ans[b]=1;
		}
		
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
		for(i=1;i<=n;i++)
			if(!ans[i])
				index++;
		printf("%d\n",index);
	}
	return 0;
}
