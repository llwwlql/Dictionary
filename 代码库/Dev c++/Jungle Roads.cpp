#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 10000000
using namespace std;
struct node{
	int u,v,w;
/*	bool operator<(const node &p)const{  
         return w<p.w;
     }*/
}edge[30];
int pre[30],n,sum;
int map[30][30];

bool cmp(node a,node b)
{
	return a.w<b.w;
}

int find(int x)
{//查找根节点 
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

void Merge(int x,int y,int w)
{//判断两个节点是否连通 
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		pre[fx]=fy;
		sum+=w;
	}
}

void Kruskal()
{//MST 
	int i,j;
	int count=0;
	for(i=1;i<=n;i++)
		pre[i]=i;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(map[i][j]!=INF)
			{
				edge[count].u=i;
				edge[count].v=j;
				edge[count++].w=map[i][j];
			}
		}
	}
	
	sort(edge,edge+count,cmp);
	for(i=0;i<count;i++)
		Merge(edge[i].u,edge[i].v,edge[i].w);
}

int main()
{
	int i,j;
	char u,v;
	int w,m;
	while(scanf("%d%*c",&n),n)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				map[i][j]=(i==j? 0:INF);
		
		for(i=1;i<n;i++)
		{
			scanf("%c %d%*c",&u,&m);
			
			while(m--)
			{
				scanf("%c %d%*c",&v,&w);
				map[u-'A'+1][v-'A'+1]=map[v-'A'+1][u-'A'+1]=w;				
			}
		}
		sum=0;
		Kruskal();
		printf("%d\n",sum);
	}
	
	return 0;
}
