#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf = 1<<30;

int T,S,D,n;
int map[1111][1111];
int vis[1111],cast[1111];
int s[1111],e[1111];

void Dijkstra()
{
    int i,j,minn,pos;
    memset(vis,0,sizeof(vis));
    vis[0] = 1;
    for(i = 0; i<=n; i++)
        cast[i] = map[0][i];
    for(i = 1; i<=n; i++)
    {
        minn = inf;
        for(j = 1; j<=n; j++)
        {
            if(cast[j]<minn && !vis[j])
            {
                pos = j;
                minn = cast[j];
            }
        }
        vis[pos] = 1;
        for(j = 1; j<=n; j++)
        {
            if(cast[pos]+map[pos][j]<cast[j] && !vis[j])
                cast[j] = cast[pos]+map[pos][j];
        }
    }
}

int main()
{
	int i,j;
	int a,b,v;
	while(scanf("%d %d %d",&T,&D,&S)!=EOF)
	{
		n=0;
		for(i=0;i<1005;i++)
			for(j=0;j<1005;j++)
				map[i][j]= (i==j)? 0:inf;
		for(i=0;i<T;i++)
		{
			scanf("%d %d %d",&a,&b,&v);
			n=max(max(n,a),b);
			if(map[a][b]>v)
				map[a][b]=map[b][a]=v;
		}
		
		for(i=0;i<D;i++)
		{
			scanf("%d",&v);
			map[0][v]=map[v][0]=0;
		}
		
		int min=inf;
		Dijkstra();
		
		for(i=0;i<S;i++)
		{
			scanf("%d",&v);
			if(min>cast[i])
				min=cast[i];
		}
		printf("%d\n",min);
	}
	
	
	return 0;
}
