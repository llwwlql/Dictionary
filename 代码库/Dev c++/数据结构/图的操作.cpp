/*测试数据：
8 9
ABCDEFGH
A B
B D
B E
E H
D H
A C
C F
C G
F G
*/

#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX 20
using namespace std;
int visit[MAX+1]={0};
typedef struct {
	char vexs[MAX];
	int A[MAX+1][MAX+1];
	int vexnum,arcnum;		//图的顶点数和边数 
}MGraph;
int LocateVex(char ch1,MGraph G)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==ch1)
			return i;
}

void InitGraph(MGraph &G)
{
	int i,j,k;
	char ch1,ch2;
	printf("请输入图的节点数和边数：");
	scanf("%d %d%*c",&G.vexnum,&G.arcnum);
	
	printf("输入节点代号：");
	for(i=0;i<G.vexnum;i++)
		scanf("%c",&G.vexs[i]);
	getchar();
	printf("请输入边：");
	for(i=0;i<G.arcnum;i++)
	{
		scanf("%c %c%*c",&ch1,&ch2);
		j=LocateVex(ch1,G);k=LocateVex(ch2,G);
		G.A[j][k]=1;
		G.A[k][j]=1;
	}
}

void DFS(int i,MGraph G)
{
	int j;
	visit[i]=1;
	printf("%c",G.vexs[i]);
	for(j=0;j<G.vexnum;j++)
		if(!visit[j] && G.A[i][j])
			DFS(j,G);
}

void BFS(MGraph G)
{
	int i,j,k;
	char ch;
	queue <char>q;
	for(i=0;i<G.vexnum;i++)
	{
		if(!visit[i])
		{
			printf("%c",G.vexs[i]);
			visit[i]=1;
			q.push(G.vexs[i]);
			while(!q.empty())
			{
				ch=q.front();
				q.pop();
				k=LocateVex(ch,G);
				for(j=0;j<G.vexnum;j++)
				{
					if(!visit[j] && G.A[k][j])
					{
						visit[j]=1;
						printf("%c",G.vexs[j]);
						q.push(G.vexs[j]);
					}
				}
			}
		}
	}
}

int main()
{
	int i,j;
	MGraph G;
	memset(G.A,0,sizeof(G.A));
	InitGraph(G);
	
	
	printf("图的深度优先搜索遍历:");
	for(i=0;i<G.vexnum;i++)
		if(!visit[i])
			DFS(i,G);
	
	memset(visit,0,sizeof(visit));
	putchar('\n');
	
	printf("图的广度优先搜索遍历:");
	
	BFS(G);
	
	return 0;
}
