#include <stdio.h>
#include <string.h>
#define INF 1000000;
int Map[205][205];
int d[205];
int n,m;
void Dij(int a,int b)
{
    int v[205];
    int i,j;
    memset(v,0,sizeof(v));
    for(i=0;i<n;i++)
        d[i]=INF;
    d[a]=0;
    for(i=0;i<n;i++)
    {
        int x,m=INF;
        for(int y=0;y<n;y++)
        {
            if(!v[y] && d[y]<=m)
            {
                x=y;
                m=d[x];
            }
        }

        v[x]=1;
        for(int y=0;y<n;y++)
        {
            if(d[y]>d[x]+Map[x][y])
                d[y]=d[x]+Map[x][y];
        }
    }

}

int main()
{
    int i,j,a,b,c;
    while(~scanf("%d %d",&n,&m))
    {
        for(i=0;i<n;i++)
            for(j=0;j<=n;j++)
                Map[i][j]=INF;

        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            Map[a][b]=c;
            Map[b][a]=c;
        }
        scanf("%d %d",&a,&b);
        Dij(a,b);
        if(d[b]!=1000000)
            printf("%d\n",d[b]);
        else
            printf("-1\n");
    }


    return 0;
}
