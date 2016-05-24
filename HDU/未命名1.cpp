#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 100010
using namespace std;
int n,m;
vector <int>map[INF];
vector <int>new_map[INF];
stack <int>s;
int used[INF],dfn[INF],low[INF],newflag,top;
bool isStack[INF];

void init()
{
	for(i=0;i<INF;i++)
		map[i].clear();
	for(i=0;i<INF;i++)
		map[i].clear();
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
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			map[a].push_back(b);
		}
		
		
	}
	return 0;
}
