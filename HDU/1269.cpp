#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10010
using namespace std;
vector <int>map[MAX];
stack <int>s;
bool isStack[MAX];
int used[MAX],dfn[MAX],low[MAX];
int newflag,top;
void init()
{
	int i;
	for(i=0;i<MAX;i++)
		map[i].clear();
	while(!s.empty())
		s.pop();
	memset(used,0,sizeof(used));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(isStack,0,sizeof(isStack));
	newflag=top=0;
}

void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	s.push(u);
	isStack[u]=true;
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

int main()
{
	int i,j,a,b;
	int n,m;
	while(scanf("%d %d",&n,&m),n+m)
	{
		init();
		
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a].push_back(b);
		}
		for(i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		if(newflag==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
