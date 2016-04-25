#include <stdio.h>
#include <string.h>
#define INF 1000000

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
                map[i][j]=INF;

        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            map[a][b]=c;
            map[b][a]=c;
        }

        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    if(map[i][j]>map[i][k]+map[k][j])
                        map[i][j]=map[i][k]+map[k][j]
            }
        }
        scanf("%d %d",&a,&b);
        printf("%d\n",map[a][b]);
    }

    return 0;
}
