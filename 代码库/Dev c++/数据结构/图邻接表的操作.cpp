#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <string.h>
#define MAX 100
using namespace std;

int visited[MAX+1];		//记录是否访问过 

typedef struct node{
	int data;
	struct node *next;
}Node,*ArcNode;
//定义邻接表的边类型

typedef struct vnode{
	char data;
	ArcNode firstarc;
}VNode;
//定义邻接表的结点类型 

typedef struct Graph{
	VNode AdjList[MAX];
	int vexnum,arcnum;
}MGraph;
//定义图类型 

int LocateVex(char ch,MGraph G)
{//取该结点在数组中的位置 
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.AdjList[i].data==ch)
			return i;
	return -1;
}

void InitGraph(MGraph &G)
{//建立一个有向图 
	int n,m;
	int i,j,k;
	char ch1,ch2;
	ArcNode p;
	printf("请输入结点个数和边个数：");
	scanf("%d %d",&G.vexnum,&G.arcnum);
	printf("请输入结点：");
	getchar();
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.AdjList[i].data);
		G.AdjList[i].firstarc=NULL;
	}
	
	printf("请输入边：");
	for(k=0;k<G.arcnum;k++)
	{
		getchar();
		scanf("%c %c",&ch1,&ch2);
		
		i=LocateVex(ch1,G);j=LocateVex(ch2,G);
		
		ArcNode e;
		e=(ArcNode)malloc(sizeof(Node));
		e->data=j;
		e->next=NULL;
		p=G.AdjList[i].firstarc;
		if(!p)
			G.AdjList[i].firstarc=e;
		
		else
		{
			while(p->next)
				p=p->next;
			p->next=e;
		}
	}
}


void DFS(MGraph G,int i)
{//深度优先搜索递归算法 
	ArcNode p;
	visited[i]=1;
	printf("%c ",G.AdjList[i].data);
	p=G.AdjList[i].firstarc;
	while(p)
	{
		if(!visited[p->data])
			DFS(G,p->data);
		p=p->next;
	}
}

void BFS(MGraph G)
{//广度优先搜索 
	queue<int>q;
	int i,j;
	ArcNode p;
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			q.push(i);
			printf("%c ",G.AdjList[i].data);
			while(!q.empty())
			{
				p=G.AdjList[q.front()].firstarc;
				while(p)
				{
					if(!visited[p->data])
					{
						visited[p->data]=1;
						printf("%c ",G.AdjList[p->data].data);
						q.push(p->data);
					}
					p=p->next;
				}
				q.pop();
			}
		}
	}
}

void DFSsearch(MGraph G)
{//深度优先搜索非递归算法 
	int i,j;
	stack <int>s;
	ArcNode p;
	memset(visited,0,sizeof(visited));
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			printf("%c ",G.AdjList[i].data);
			
			s.push(i);
			
			p=G.AdjList[i].firstarc;
			while(!s.empty())
			{
				while(p)
				{
					if(!visited[p->data])
					{
						visited[p->data]=1;
						printf("%c ",G.AdjList[p->data]);
						s.push(p->data);
						p=G.AdjList[p->data].firstarc;
					}
					else
						p=p->next;
				}
				p=G.AdjList[s.top()].firstarc;
				s.pop();
			}
		}
	}
}

void FindInDegree(MGraph G,int *indegree)
{
	int i;
	ArcNode p;
	for(i=0;i<G.vexnum;i++)
	{
		p=G.AdjList[i].firstarc;
		while(p)
		{
			indegree[p->data]++;
			p=p->next;
		}
	}
}

int TopologicalSort(MGraph G)
{
	int indegree[MAX]={0};
	int i,j,k;
	FindInDegree(G,indegree);
	
	stack <int>s;
	
	ArcNode p;
	for(i=0;i<G.vexnum;i++)
	{
		if(!indegree[i])
			s.push(i);
	}
	
	int count=0;
	
	while(!s.empty())
	{
		i=s.top();
		s.pop();
		printf("%c ",G.AdjList[i].data);
		count++;
		for(p=G.AdjList[i].firstarc;p;p=p->next)
		{
			k=p->data;
			if(!(--indegree[k]))
				s.push(k);
		}//for
	}//while
	if(count<G.vexnum)
		return 0;
	else
		return 1;
}

int main()
{
	int i,K;
	MGraph G;
	InitGraph(G);
	
	memset(visited,0,sizeof(visited));
	
	ArcNode p;
	p=G.AdjList[0].firstarc;
	
	printf("深度优先搜索的递归遍历："); 
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
			DFS(G,i);
	}
	putchar('\n');
	memset(visited,0,sizeof(visited));
	printf("广度优先搜索的遍历："); 
	BFS(G);
	putchar('\n');

	printf("深度优先搜索的非递归遍历："); 
	DFSsearch(G);
	putchar('\n');
	//拓扑排序
	printf("拓扑排序序列为：");
	K=TopologicalSort(G);
	if(K)
		printf("\n该图是个有向无环图\n");
	else
		printf("\n该图是个有环图\n");
	//判断是有向无环图
	
	return 0;
}
