#include <stdio.h>
#include <string.h>
#define INF 10000000

int map[205][205];
int main()
{
    int n,m;
    int a,b,c;
    int i,j,k;
    while(~scanf("%d %d",&n,&m))
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                map[i][j]= i==j? 0:INF;

        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(map[a][b]>c)
                map[a][b]=map[b][a]=c;
        }

        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    if(map[i][j]>map[i][k]+map[k][j])
                        map[i][j]=map[i][k]+map[k][j];
            }
        }
        scanf("%d %d",&a,&b);
        if(map[a][b]!=INF)
            printf("%d\n",map[a][b]);
        else
            printf("-1\n");
    }

    return 0;
}
