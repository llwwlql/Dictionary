#include <stdio.h>
#include <string.h>
#define INF 1000000
typedef struct graph{
	int vexnum;
	int arcnum;
	char elem[105];
	int edge[100][100];
}Graph;
//图的数据类型
struct edge{
	int adjvex;
	int lowcost;
}closedge[105];
//Prim算法的辅助矩阵
int lowcost[105][105];

int LocateVex(char ch,Graph G)
{
	int j;
	for(j=1;j<=G.vexnum;j++)
		if(ch==G.elem[j])
			return j;
}

void Prim(Graph G,int start)
{
	int i,j,k;
	int min;
	for(i=1;i<=G.arcnum;i++)
	{
		if(i!=start)
		{
			closedge[i].adjvex=start;
			closedge[i].lowcost=G.edge[start][i];
		}
	}
	closedge[start].lowcost=0;
	for(i=2;i<=G.vexnum;i++)
	{
		min=INF;
		for(j=1;j<=G.vexnum;j++)
		{
			if(closedge[j].lowcost && closedge[j].lowcost<min)
			{
				k=j;
				min=closedge[j].lowcost;
			}
		}
		
		printf("%c %c\n",G.elem[closedge[k].adjvex],G.elem[k]);
		lowcost[k][closedge[k].adjvex]=1;
		lowcost[closedge[k].adjvex][k]=1;
		
		closedge[k].lowcost=0;
		
		for(j=1;j<=G.arcnum;j++)
		{
			if(G.edge[k][j]<closedge[j].lowcost)
			{
				closedge[j].lowcost=G.edge[k][j];
				closedge[j].adjvex=k;
			}
		}
	}
}


int main()
{
	int i,j,k;
	Graph G;
	int n,m,c;
	char a,b;
	printf("请输入结点个数和边的条数:\n");
	scanf("%d %d%*c",&G.vexnum,&G.arcnum);
	
	printf("请输入结点名称:");
	for(i=1;i<=G.vexnum;i++)
		scanf("%c",G.elem+i);
	getchar();
	printf("请输入边:\n");	
	for(i=1;i<=G.arcnum;i++)
		for(j=1;j<=G.arcnum;j++)
			G.edge[i][j]=INF;
	for(i=0;i<G.arcnum;i++)  
    {  
        scanf("%c %c %d%*c",&a,&b,&c);  
        j=LocateVex(a,G);k=LocateVex(b,G);  
        G.edge[j][k]=c;  
        G.edge[k][j]=c;
    }
    memset(lowcost,0,sizeof(lowcost));
	printf("最小生成树:\n");
	Prim(G,1);

	return 0;
}
