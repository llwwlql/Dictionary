#include <stdio.h>
#include <string.h>
#define INF 1<<30
int map[111][111];
int p[111][111];
int vis[111],dis[111],vla[111];
int k,n,r;
void init()
{
	int i,j;
	for(i=0;i<111;i++)
	{
		for(j=0;j<111;j++)
		{
			map[i][j]=(i==j)? 0:INF;
			p[i][j]= (i==j)? 0:INF;
		}
	}
}

void dijkstra()
{
	int i,j;
	int mark,min;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for(i=1;i<=n;i++)
		dis[i]=map[1][i];
	for(i=1;i<=n;i++)
		vla[i]=p[1][i];
	for(i=1;i<=n;i++)
	{
		min=INF;
		for(j=1;j<=n;j++)
		{
			if(!vis[j] && dis[j]<min)
			{
				min=dis[j];
				mark=j;
			}
		}
		vis[mark]=1;
		
		for(j=1;j<=n;j++)
		{
			if(!vis[j])
			{
				if(dis[j] > dis[mark] + map[mark][j] && vla[mark] + p[mark][j] <= k)
				{
					dis[j] = dis[mark] + map[mark][j];
					vla[j] = vla[mark] + p[mark][j];
				}
				else if(dis[j] == dis[mark] + map[mark][j] && vla[j]> vla[mark] + p[mark][j])
					vla[j] = vla[mark] + p[mark][j];
			}
		}
	}
	
	for(i=1;i<=n;i++)
		printf("<%d %d>\n",dis[i],vla[i]);
}

int main()
{
	int a,b,c,d;
	int i,j;
	while(~scanf("%d %d %d",&k,&n,&r))
	{
		init();
		for(i=0;i<r;i++)
		{
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(c<map[a][b])
			{
				map[a][b]=map[b][a]=c;
				p[a][b]=p[b][a]=c;
			}				
			else if(map[a][b]==c)
			{
				map[a][b]=map[b][a]=c;
				p[a][b]=p[b][a]=c;
			}			
		}
		dijkstra();
		printf("%d\n",dis[n]);
	}	
	return 0;
}
