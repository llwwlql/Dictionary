#include <stdio.h>
#include <algorithm>
using namespace std;
struct node{
	int u,v,w;
}edge[105];
int pre[30];
int n,sum,Count;
bool cmp(node a,node b)
{
	return a.w<b.w;
}

int find(int x)
{
	int r=x;
	while(r!=pre[r])
		r=pre[r];
	int i=x,j;
	while(i!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}

void Kruskal()
{
	int i,j,fx,fy;
	sum=0;
	sort(edge,edge+Count,cmp);
	for(i=0;i<n;i++)
		pre[i]=i;
	
	for(i=0;i<Count;i++)
	{
		fx=find(edge[i].u);
		fy=find(edge[i].v);
		if(fx!=fy)
		{
			sum+=edge[i].w;
			pre[fx]=fy;
		}
	}
}

int main()
{
	int i,j;
	int w,m;
	char u,v;
	while(scanf("%d%*c",&n),n)
	{
		Count=0;
		for(i=1;i<n;i++)
		{
			scanf("%c %d%*c",&u,&m);
			while(m--)
			{
				scanf("%c %d%*c",&v,&w);
				edge[Count].u=u-'A';
				edge[Count].v=v-'A';
				edge[Count++].w=w;
			}
		}
		Kruskal();
		printf("%d\n",sum);
	}
	
	return 0;
}
