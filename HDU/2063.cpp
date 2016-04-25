#include <stdio.h>
#include <string.h>
#define MAX 505
int map[MAX][MAX];
int visit[MAX];
int ok[MAX];
int k,n,m;
int Find(int x)
{
	int i;
	for(i=1;i<=m;i++)
	{
		if(map[x][i]==1 && !visit[i])
		{
			visit[i]=1;
			if(!ok[i])
			{
				ok[i]=x;
				return 1;
			}
			else
			{
				if(Find(ok[i]))
				{
					ok[i]=x;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int i,j;
	int a,b;
	while(scanf("%d",&k),k)
	{
		int ans=0;
		memset(map,0,sizeof(map));
		memset(ok,0,sizeof(ok));
		
		scanf("%d %d",&n,&m);
		for(i=1;i<=k;i++)
		{
			scanf("%d %d",&a,&b);
			map[a][b]=1;
		}
		
		for(i=1;i<=n;i++)
		{
			memset(visit,0,sizeof(visit));
			if(Find(i))
				ans++;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
