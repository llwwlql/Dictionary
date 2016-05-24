#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf 99999
using namespace std;

int map[1010][1010];
int vis[1111],dis[1111];
int T,n;

void Dijkstra()
{
	int i,j;
	int mark;
	memset(vis,0,sizeof(vis));
	for(i=0;i<=n;i++)
		dis[i]=map[0][i];
	vis[0]=1;
	
	for(i=1;i<=n;i++)
	{
		int min=inf;
		
		for(j=1;j<=n;j++)
		{
			if(dis[j]<min && !vis[j])
			{
				min=dis[j];
				mark=j;
			}	
		}
		vis[mark]=1;
		
		for(j=1;j<=n;j++)
		{
			if(dis[j]>dis[mark]+map[mark][j] && !vis[j])
				dis[j]=dis[mark]+map[mark][j];				
		}
	}
}

int main()
{
	int a,b,time;
	int i,j;
	int s,d;
	while(~scanf("%d %d %d",&T,&s,&d))
	{
		for(i=0;i<1005;i++)
			for(j=0;j<1005;j++)
				map[i][j]=(i==j)? 0:inf;
		n=0;
		while(T--)
        {
            scanf("%d%d%d",&a,&b,&time);
            n = max(max(n,a),b);
            if(time<map[a][b])
                map[a][b] = map[a][b] = time;
        }
        
        for(i = 0; i<s; i++)
        {
            scanf("%d",&a);
            map[0][a]= map[a][0] = 0;
        }
        int min = inf;
        
		Dijkstra();
		
		for(i=0;i<d;i++)
		{
			scanf("%d",&b);
			if(min>dis[b])
				min=dis[b];
		}
		printf("%d\n",min);
	}
	return 0;
}
