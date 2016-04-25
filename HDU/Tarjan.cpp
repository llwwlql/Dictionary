#include <stdio.h>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#define MAX 10000+10
using namespace std;
vector <int> map[MAX];
stack <int>s;
int dfn[MAX],low[MAX],used[MAX];
bool isStack[MAX];
int newflag,top;

void init()
{
	int i;
	for(i=0;i<MAX;i++)
		map[i].clear();
	while(!s.empty())
		s.pop();
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(used,0,sizeof(used));
	memset(isStack,0,sizeof(isStack));
	newflag=0;
	top=0;
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
				low[u]=low[v];
		}
		else if(isStack[u] && dfn[v]<low[u])
			low[u]=dfn[v];
	}
	if(dfn[u]==low[u])
	{
		newflag++;
		int x;
		do{
			x=s.top();
			isStack[x]=false;
			s.pop();
			used[x]=newflag;
		}while(x!=u);
	}
	return ;
}

int main()
{
	int n,m;
	int i,j,a,b;
	while(scanf("%d %d",&n,&m),n+m)
	{
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
		
		if(newflag==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
