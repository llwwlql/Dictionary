#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <stack>
#define MAX 1010
using namespace std;	
struct node{
	int u,v;
}temp[20005];
vector <int> map[MAX];
stack <int>s;
int dfn[MAX],low[MAX];
bool isStack[MAX];
int used[MAX],newflag,top;
int n,m;
int _max;

void init1()
{
	int i;
	for(i=0;i<MAX;i++)
		map[i].clear();
	_max=0;
}

void init2()
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(isStack,0,sizeof(isStack));
	memset(used,0,sizeof(used));
	while(!s.empty())
		s.pop();
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
		int index=0; 
		do{
			x=s.top();
			isStack[x]=false;
			used[x]=newflag;
			s.pop();
			index++;
		}while(x!=u);
		if(index>_max)
			_max=index;
	}
	return ;	
}

int main()
{
	int i,j;
	int T;
	int k,a,b,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		init1();
		init2();
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			temp[i].u=a;
			temp[i].v=b;
			map[a].push_back(b);			
		}
		
		for(i=1;i<=n;i++)
		{
			if(!dfn[i])
				tarjan(i);
		}
		int r=_max;
		
		for(j=1;j<=k;j++)
		{
			init2();
			scanf("%d",&p);
			_max=r;
			
			map[temp[p].v].push_back(temp[p].u);
			tarjan(temp[p].v);
			map[temp[p].v].pop_back();
			printf("%d\n",_max);
		}
	}
}
