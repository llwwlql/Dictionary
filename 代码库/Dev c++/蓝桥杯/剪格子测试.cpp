#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int map[20][20],vis[20][20],s,n,m;
int to[4][2] = {1,0,-1,0,0,1,0,-1};

int dfs(int x,int y,int sum)
{
    if(sum == s)
    return 1;
    int ans = 0;
    for(int i = 0;i<4;i++)
    {
        int tx = x+to[i][0];
        int ty = y+to[i][1];
        if(tx >=0 && tx<n && ty>=0 && ty<m)
        {
            if(!vis[tx][ty] && map[tx][ty]+sum<=s)
            {
                vis[tx][ty] = 1;
                ans=dfs(tx,ty,map[tx][ty]+sum);
                if(ans)
                return ans+1;
                vis[tx][ty] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    int i,j;
    int sum = 0;
    cin >> m >> n;
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<m;j++)
        {
            cin >> map[i][j];
            sum+=map[i][j];
        }
    }
    if(sum%2)
    printf("0\n");
    else if(map[0][0] == sum/2)
    printf("1\n");
    else
    {
        s = sum/2;
        memset(vis,0,sizeof(vis));
        vis[0][0] = 1;
        printf("%d\n",dfs(0,0,map[0][0]));
    }

    return 0;
}

