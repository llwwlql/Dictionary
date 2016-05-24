#include <stdio.h>
int ans[105][105];
int count=0;
int n;
struct f{
	int adjvex;
	int lowcost;
}closedge[1005];

void Prim(int start)
{
	int i,j,k;
	int min;
	closedge[start].lowcost=0;
	
	for(j=1;j<=n;j++)
	{
		if(ans[start][j]<closedge[j].lowcost)
		{
			closedge[j].lowcost=ans[start][j];
			closedge[j].adjvex=start;
		}
	}
	
	for(i=3;i<=n;i++)
	{
		min=1005;
		for(j=1;j<=n;j++)
		{
			if(closedge[j].lowcost && closedge[j].lowcost<min)
			{
				k=j;
				min=closedge[j].lowcost;
			}
		}
		count+=closedge[k].lowcost;
		closedge[k].lowcost=0;
		
		for(j=1;j<=n;j++)
		{
			if(ans[k][j]<closedge[j].lowcost)
			{
				closedge[j].lowcost=ans[k][j];
				closedge[j].lowcost=k;
			}
		}
	}
}

int main()
{
	int q,a,b;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			ans[i][j]=1005;
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",ans[i]+j);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&a,&b);
		count=0;
		for(i=1;i<=n;i++)
			closedge[i].lowcost=1005;
		
		for(i=1;i<=n;i++)
		{
			if(i!=a)
			{
				closedge[i].adjvex=a;
				closedge[i].lowcost=ans[a][i];
			}
		}
		
		closedge[a].lowcost=0;
		
		Prim(b);
		printf("%d\n",count);
	}
	
	return 0;
}
