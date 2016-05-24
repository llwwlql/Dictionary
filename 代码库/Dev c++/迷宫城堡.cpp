#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>
#define MAX 10005
using namespace std;
vector <int> map[MAX];
stack <int> s;
int isStack[MAX];
int dfn[MAX],low[MAX],used[MAX];
int top,newflag;
void init()
{//各种初始化 
	while(!s.empty())
		s.pop();
	for(int i=0;i<MAX;i++)
		map[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(dfn,0,sizeof(low));
	memset(used,0,sizeof(used));
	memset(isStack,0,sizeof(isStack));
	top=0;
	newflag=0;
}

void Tarjan(int u)
{
	dfn[u]=low[u]=++top;	//时间戳 
	isStack[u]=1;	//存在栈中 
	s.push(u);
	for(int x=0;x<map[u].size();x++)
	{
		int v=map[u][x];
		if(!dfn[x])//判断是否更新过
		{
			Tarjan(v);
			if(low[v]<low[u])
			{
				low[u]=low[v];
			}
		}
		else if(isStack[v] && dfn[v]<low[u])
		{
			low[u]=dfn[v];
		}
	}
	if(dfn[u]==low[u])
	{
		newflag++;
		int x;
		do{
			x=s.top();
			isStack[x]=0;
			used[x]=newflag;
			s.pop();
		}while(x!=u);
	}
}

int main()
{
	int n,m;
	int i,j;
	int a,b;
	while(scanf("%d %d",&n,&m),n+m)
	{
		init();
		
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a].push_back(b);
		}
		for(i=1;i<=n;i++){
			if(!dfn[i])
			{
				Tarjan(i);
			}
		}
		if(newflag==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
