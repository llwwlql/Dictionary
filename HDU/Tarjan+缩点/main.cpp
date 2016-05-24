#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 100010
using namespace std;
int n,m;
vector <int> Map[INF];
vector <int> new_map[INF];
stack <int> s;
int used[INF],dfn[INF],low[INF],newflag,top;
int vis[INF],sum,temp;
bool isStack[INF];

void init()
{
    int i;
    while(!s.empty())
        s.pop();

	for(i=0;i<INF;i++)
		Map[i].clear();
	for(i=0;i<INF;i++)
		Map[i].clear();
    memset(used,0,sizeof(used));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(isStack,0,sizeof(isStack));
    memset(vis,0,sizeof(vis));
    newflag=top=temp=0;
    sum=INF;
}

void tarjan(int u)
{
    int x;
    dfn[u]=low[u]=++newflag;
    s.push(u);
    isStack[u]=true;
    for(x=0;x<Map[u].size();x++)
    {
        int v=Map[u][x];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(!isStack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        newflag++;
        int x;
        do{
            x=s.top();
            isStack[x]=false;
            used[x]=newflag;
            s.pop();
        }while(x!=u);
    }
    return ;
}

void getbit()
{
    int i,j;
    int v,u;
    for(i=0;i<n;i++)
    {
        v=used[i];
        for(j=0;j<Map[i].size();j++)
        {
            u=used[Map[i][j]];
            if(u!=v)
            {
                new_map[v].push_back(u);
            }
        }
    }
}

void dfs(int u,int t)
{
    int i,v;
    if(u==used[n-1])
    {
        if(t<sum)
            sum=t;
        return ;
    }
    for(i=0;i<new_map[u].size();i++)
    {
        v=new_map[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            dfs(v,t+1);
            vis[v]=0;
        }
    }
}

int main()
{
	int T;
	int a,b,i,j;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			Map[a].push_back(b);
		}
		for(i=0;i<n;i++)
        {
            if(!dfn[i])
            {
                tarjan(i);
            }
        }
        getbit();
        vis[0]=1;
        dfs(0,0);
        if(!temp)
            printf("-1\n");
        else
            printf("%d\n",sum);
	}
	return 0;
}
