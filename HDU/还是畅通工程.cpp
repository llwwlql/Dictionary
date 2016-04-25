#include <stdio.h>
#include <algorithm>
using namespace std;
struct node{
	int x,y;
	int w;
}edge[5050];
int pre[5005];
int sum;
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
		j=pre[i]; pre[i]=r; i=j;
	}
	return r;
}

void Kruskal(int n,int m)
{
	int i,j;
	for(i=1;i<=n;i++)
		pre[i]=i;
	sort(edge,edge+m,cmp);
	sum=0;
	for(i=0;i<m;i++)
	{
		int fx=find(edge[i].x),fy=find(edge[i].y);
		if(fx!=fy)
		{
			pre[fx]=fy;
			sum+=edge[i].w;
		}
	}
}

int main()
{
	int n;
	int i,j;
	int a,b,c;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n*(n-1)/2;i++)
			scanf("%d %d %d",&edge[i].x,&edge[i].y,&edge[i].w);
		Kruskal(n,n*(n-1)/2);
		printf("%d\n",sum);
	}
	
	return 0;
}
