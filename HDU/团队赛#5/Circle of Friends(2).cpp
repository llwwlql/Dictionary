#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>
#define MAX 100010 
using namespace std;
vector <int> map[MAX];
vector <int> map2[MAX];
stack <int>s;
int dfn[MAX],low[MAX];
bool isStack[MAX];
int used[MAX],newflag,top;
int n,m;

void init()
{//赋初值
	int i;
	for(i=0;i<MAX;i++)
	{
		map[i].clear();
		map2[i].clear();
	}
		
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(isStack,0,sizeof(isStack));
	memset(used,0,sizeof(used));
	while(!s.empty())
		s.pop();
	newflag=0;top=0;
}

void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	isStack[u]=true;
	s.push(u);
	for(int x=0;x<map[u].size();x++)
	{
		int v=map[u][x];
		if(!dfn[v])
		{
			tarjan(v);
			if(low[v]<low[u])
			{
				low[u]=low[v];
			}
		}
		else if(isStack[v] && dfn[v]<low[u])	//如果v在栈中并且dfn[v]<low[u]
			low[u]=dfn[v];
	}
	if(dfn[u]==low[u])	//找到了连通分量的结束条件
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

void getmap()
{
	int i,j,u;
	for(i = 0;i < n ; i++)
	{
		u=used[i];
		for(int x=0;x<map[i].size();x++)
		{
			int v=map[u][x];
			if(used[v] == u)
				continue;
			map2[u].push_back(v);
		}
	}
}
int dp(int s)  
{  
    if(s==used[n-1])  
        return 0;  
    int ans=MAX;  
    int len=map2[s].size();  
    for(int i=0;i<len;i++) 
    	if(ans>dp(map2[s][i])+1)
    		ans=dp(map2[s][i])+1;
    return ans;  
}

int main()
{
	int i,j;
	int a,b;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		init();
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a].push_back(b);
		}
		for(i=1;i<=n;i++)
		{
			if(!dfn[i])
				tarjan(i);
		}
		
		getmap();
		int gg=dp(used[0]); 
		if(gg==MAX)  
        printf("-1\n");  
    	else  
        printf("%d\n",gg); 
	}
}

