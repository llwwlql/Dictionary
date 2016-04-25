#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NODE 3200010
#define N 100010
int n;
int v[N];
int node;
int next[NODE][2];
int end[NODE];
void add(int cur,int k)
{
    memset(next[node],0,sizeof(next[node]));
    end[node]=0;
    next[cur][k]=node++;
}
int cal(int x)
{
    int i,k,cur=0;
    for(i=30;i>=0;i--)
    {
        k=((1<<i)&x)?0:1;
        if(next[cur][k]) cur=next[cur][k];
        else    cur=next[cur][1-k];
    }
    return (x^end[cur]);
}
int main()
{
    int i,j,k,x,cur;
    int ans;
    while(~scanf("%d",&n))
    {
        node=1;
        memset(next[0],0,sizeof(next[0]));
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            v[i]=x;
            cur=0;
            for(j=30;j>=0;j--)
            {
                k=((1<<j)&x)?1:0;
                if(next[cur][k]==0) add(cur,k);
                cur=next[cur][k];
            }
            end[cur]=x;
        }
        for(ans=i=0;i<n;i++)    ans=MAX(ans,cal(v[i]));
        printf("%d\n",ans);
    }
    return 0;
}
