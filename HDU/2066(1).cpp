#include <stdio.h>
#include <algorithm>
#include <string.h> 
using namespace std;
const int inf = 1<<30;
int map[1111][1111];
int vis[1005],dis[1005];
int s[1111],e[1111];
int n;

void Dijkstra()
{
	int i,j;
	memset(vis,0,sizeof(vis));
	for(i=0;i<=n;i++)
		dis[i]=map[0][i];
	vis[0]=1;
	
	for(i=1;i<=n;i++)
	{
		
		int mark=-1,min=inf;
		
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
    int i,j,x,y,z,start,end;
    int T,S,D;
    while(~scanf("%d%d%d",&T,&S,&D))
    {
        n = 0;
        for(i = 0; i<1111; i++)
        {
            for(j = 0; j<1111; j++)
                map[i][j] = inf;
            map[i][i] = 0;
        }
        while(T--)
        {
            scanf("%d%d%d",&x,&y,&z);
            n = max(max(n,x),y);
            if(z<map[x][y])
                map[x][y] = map[y][x] = z;
        }
        int minn = inf;
        for(i = 0; i<S; i++)
        {
            scanf("%d",&s[i]);
            map[0][s[i]] = map[s[i]][0] = 0;
        }
        for(i = 0; i<D; i++)
            scanf("%d",&e[i]);
        Dijkstra();
        for(i = 0; i<D; i++)
            minn = min(minn,dis[e[i]]);
        printf("%d\n",minn);
    }
    return 0;
}
