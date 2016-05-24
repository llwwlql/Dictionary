#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>
#define MAX 100010
using namespace std;

vector <int>map[MAX];
stack <int>s;
int dfn[MAX],low[MAX];
bool isStack[MAX];
int used[MAX],newflag,top;
int n,m;
int vis[MAX];
int peace,acount=0;
void init()
{
	int i;
	for(i=0;i<MAX;i++)
		map[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(isStack,0,sizeof(isStack));
	memset(used,0,sizeof(used));
	memset(vis,0,sizeof(vis));
	while(!s.empty())
		s.pop();
	newflag=0,top=0;
}

void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	isStack[u]=true;
	s.push(u);
	if(acount==1 && u==n-1)
		peace=1;
	for(int x=0;x<map[u].size();x++)
	{
		int v=map[u][x];
		if(!dfn[v])
		{
			tarjan(v);
			if(low[v]<low[u])
				low[u]=low[v];
		}
		else if(isStack[v] && dfn[v]<low[u])
			low[u]=dfn[v];
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

//void dfs(int u)
//{
//	if(peace)
//		return ;
//	if(u==n-1)
//	{
//		peace=1;
//		return ;
//	}
//	for(int x=0;x<map[u].size();x++)
//	{
//		int v=map[u][x];
//		if(!vis[v])
//		{
//			vis[v]=1;
//			dfs(v);
//			vis[v]=0;
//		}
//	}
//}

int main()
{
	int i,j;
	int a,b;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a].push_back(b);
		}
		acount=0;
		peace=0;
		for(i=0;i<n;i++)
		{
			acount++;
			if(!dfn[i])
			{
				tarjan(i);
			}
		}
		if(!peace)
			printf("%d\n",-1);
		else
			printf("%d\n",newflag-1);
	}
	
	return 0;
}
