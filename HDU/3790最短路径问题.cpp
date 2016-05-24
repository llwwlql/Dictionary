#include <stdio.h>
#include <string.h>
#define INF 1<<30
int map[1111][1111];	//¾àÀë 
int vis[1111],dis[1111],val[1111];
int p[1111][1111];		//»¨·Ñ 
int s,t,n;

void dijkstra()
{
	int i,j;
	int mark,mindis,minval;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)
	{
		dis[i]=map[s][i];
		val[i]=p[s][i];
	}

	vis[s]=1;
	for(i=1;i<=n;i++)
	{
		mindis=INF;
		minval=INF;
		for(j=1;j<=n;j++)
		{
			if(!vis[j])
			{
				if(dis[j]<mindis || dis[j]==mindis && val[j]<minval)
				{
					mindis=dis[j];
					minval=val[j];
					mark=j;
				}
			}
		}
		vis[mark]=1;
		for(j=1;j<=n;j++)
		{
			if(!vis[j])
			{
				 if(dis[j]>dis[mark] + map[mark][j] || dis[j]==dis[mark] + map[mark][j] && val[j]>val[mark]+p[mark][j])
				 {
				 	dis[j]=dis[mark] + map[mark][j];
				 	val[j]=val[mark] + p[mark][j];
				 }
			}
		}
	}
}

int main()
{
	int m;
	int i,j;
	int a,b,c,d;
	while(scanf("%d %d",&n,&m),n||m)
	{
		
		for(i=0;i<1010;i++)
		{
			for(j=0;j<1010;j++)
			{
				map[i][j]=INF;
				p[i][j]=INF;
			}
				
		}
		
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(map[a][b]>c)
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
		scanf("%d %d",&s,&t);
		dijkstra();
		printf("%d %d\n",dis[t],val[t]);
	}
	
	return 0;
}
