#include <stdio.h>
#include <string.h>
#define INF 1<<30

int map[205][205];
int vis[205],dis[205];
int n;
int s,t;

void dijkstra()
{
	int mark,min;
	int i,j;
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	for(i=0;i<n;i++)
		dis[i]=map[s][i];
		
	for(i=0;i<n;i++)
	{
		min=INF;
		for(j=0;j<n;j++)
		{
			if(!vis[j] && dis[j]<min)
			{
				min=dis[j];
				mark=j;
			}
		}
		vis[mark]=1;
		for(j=0;j<n;j++)
		{
			if(!vis[j] && dis[j]>dis[mark] + map[mark][j])
				dis[j]=dis[mark] + map[mark][j];				
		}
	}
}

int main()
{
	int m;
	int a,b,c;
	int i,j;
	while(~scanf("%d %d",&n,&m))
	{
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				map[i][j]= (i==j)? 0:INF;
		
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(c<map[a][b])
				map[a][b]=map[b][a]=c;
		}
		scanf("%d %d",&s,&t);
		
		dijkstra();
		int min=INF;
		if(dis[t]==INF)
			printf("-1\n");
		else
			printf("%d\n",dis[t]);
	}
	
	return 0;
}
