#include <stdio.h>
#include <string.h>
#define INF 1<<30
int n;

int map[1111][1111];
int vis[1111],dis[1111];

int MAX(int a,int b)
{
	return a>b? a:b;
}

void dijkstra()
{
	int i,j;
	int mark,min;
	memset(vis,0,sizeof(vis));
	for(i=0;i<=n;i++)
		dis[i]=map[0][i];
	vis[0]=1;
	
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
			if(!vis[j] && dis[j]>dis[mark]+map[mark][j])
				dis[j]=dis[mark]+map[mark][j];
		}
	}
	
}

int main()
{
	int T,s,d;
	int a,b,c;
	int x,y;
	int i,j;
	while(scanf("%d %d %d",&T,&s,&d)!=EOF)
	{
		n=0;
		
		for(i=0;i<1010;i++)
		{
			for(j=0;j<1010;j++)
				map[i][j]=INF;
		}
		
		for(i=1;i<=T;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			
			n=MAX(MAX(n,a),b);
			
			if(map[a][b]>c)
				map[a][b]=map[b][a]=c;						
		}
		
		for(i=0;i<s;i++)
		{//起始点 
			scanf("%d",&x);
			map[0][x]=map[x][0]=0;
		}
		dijkstra();
		int min=INF;
		for(i=0;i<d;i++)
		{//终止点
			scanf("%d",&y);
			if(min>dis[y])
				min=dis[y];		
		}
		printf("%d\n",min);
	}
	
	return 0;
}
