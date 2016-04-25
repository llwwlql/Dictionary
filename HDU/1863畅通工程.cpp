#include <stdio.h>
#include <algorithm>
using namespace std;
struct node{
	int u,v,w;
}edge[105];
int pre[105];
int n,m;
int sum,index;
int cmp(node a,node b)
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
	int i,j;
	sum=0;
	for(i=1;i<=n;i++)
		pre[i]=i;
	for(i=0;i<m;i++)
	{
		int fx=find(edge[i].u),fy=find(edge[i].v);
		if(fx!=fy)
		{
			pre[fx]=fy;
			sum+=edge[i].w;
		}
	}
	index=0;
	for(i=1;i<=n;i++)
		if(pre[i]==i)
			index++;
	if(index==1)	
		printf("%d\n",sum);
	else
		printf("?\n");
}

int main()
{
	int i,j;
	int a,b;
	while(scanf("%d %d",&m,&n),m)
	{
		for(i=0;i<m;i++)
			scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
		sort(edge,edge+m,cmp); 
		Kruskal();
	}	
	return 0;
}
