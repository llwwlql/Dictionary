#include <cstring>
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF =0x3f3f3f3f;
int low[N];
int DFN[N];
int Instack[N];
stack<int>s;
int Incomp[N];
vector<int>gra[N];
vector<int>newgra[N];
int numcomp,cc;
int n,m;
void init()
{
    memset(low,0,sizeof(low));
    memset(DFN,0,sizeof(DFN));
    memset(Instack,0,sizeof(Instack));
    numcomp=cc=0;
    for(int i=0;i<n;i++)
        gra[i].clear();
    while(!s.empty())
        s.pop();
        int u,v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        gra[u].push_back(v);
    }

}
void tarjan(int u)
{
    low[u]=DFN[u]=++cc;
    s.push(u);
    Instack[u]=1;
    int len=gra[u].size();
    int v;
    for(int i=0;i<len;i++)
    {
        v=gra[u][i];
        if(!DFN[v])
        {
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(Instack[v])
            low[u]=min(low[u],low[v]);
    }
    if(low[u]==DFN[u])
    {
        numcomp++;
        while(!s.empty())
        {
            v=s.top(),s.pop();
            Incomp[v]=numcomp;
            Instack[v]=0;
            if(u==v)
                break;
        }
    }
}
int dp(int s)
{
    if(s==Incomp[n-1])
        return 0;
    int ans=INF;
    int len=newgra[s].size();
    for(int i=0;i<len;i++)
        ans=min(ans,dp(newgra[s][i])+1);
    return ans;
}
void solve()
{
    for(int i=0;i<n;i++)
    {
        if(!DFN[i])
            tarjan(i);
    }
    if(Incomp[0]==Incomp[n-1])
    {
        printf("0\n");
        return ;
    }
    int u,v;
    for(int i=0;i<n;i++)
        newgra[i].clear();
    for(int i=0;i<n;i++)
    {
        int len=gra[i].size();
        u=Incomp[i];
        for(int j=0;j<len;j++)
        {
            v=Incomp[gra[i][j]];
            if(u!=v)
            {
                newgra[u].push_back(v);
            }
        }
    }
    int gg=dp(Incomp[0]);
    if(gg==INF)
        printf("-1\n");
    else
        printf("%d\n",gg);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        solve();
    }
    return 0;
}

