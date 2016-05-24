#include <stdio.h>
#include <string.h>
#define INF 1<<30
int start,end;
int map[1005][1005],vis[1005],dis[2][1005];
int p[1005][1005];
int n,m;
void dijkstra()
{
	int mark,min;
	int i,j;
	memset(vis,0,sizeof(vis));
	vis[start]=1;
	for(i=1;i<=n;i++)
	{
		dis[0][i]=map[start][i];
		dis[1][i]=p[start][i];
	}
	dis[0][start]=0;
	dis[1][start]=0;
	for(i=1;i<=n;i++)
	{
		min=INF;
		for(j=1;j<=n;j++)
		{
			if(!vis[j] && dis[0][j]<min)
			{
				min=dis[0][j];
				mark=j;
			}
		}
		vis[mark]=1;

		for(j=1;j<=n;j++)
		{
			if(!vis[j] && dis[0][j] > dis[0][mark] + map[mark][j])
			{
				dis[0][j] = dis[0][mark] + map[mark][j];
				dis[1][j] = dis[1][mark] + p[mark][j];
			}
				
			else if(!vis[j] && dis[0][j] > dis[0][mark] + map[mark][j] && dis[1][j] > dis[1][mark] + p[mark][j])
			{
				dis[0][j] = dis[0][mark] + map[mark][j];
				dis[1][j] = dis[1][mark] + p[mark][j];
			}
		}
	}

}

int main()
{
	int i,j;
	int a,b,c,d;
	while(scanf("%d %d",&n,&m),n||m)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
					map[i][j]= (i==j) ? 0 : INF;
					p[i][j] = (i==j) ? 0 : INF;
			}
			

		for(i=1;i<=m;i++)
		{
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(c<map[a][b])
			{
				map[a][b]=map[b][a]=c;
				p[a][b]=p[b][a]=d;
			}
			else if(map[a][b]==c)  
            {  
                if(p[a][b]>d)  
                	p[a][b]=p[b][a]=d;
            }  
		}
		scanf("%d %d",&start,&end);
		dijkstra();

		printf("%d %d\n",dis[0][end],dis[1][end]);

	}

	return 0;
}
